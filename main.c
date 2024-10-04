/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:27:27 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 12:32:55 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_sig;

int	count_heredoc(char *prompt)
{
	int	i;
	int	count;
	int	size_delim;

	size_delim = 0;
	i = 0;
	count = 0;
	while (prompt[i])
	{
		if (prompt[i] == '<')
		{
			if (prompt[i + 1] == '<')
				count++;
			while (prompt[i] && (prompt[i] == ' '
					|| (prompt[i] >= '\t' && prompt[i] <= '\r')))
				i++;
			while (prompt[i] && ft_isalnum(prompt[i]))
			{
				size_delim++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

int	minishell(t_mini *mini, char *prompt)
{
	mini->here_doc = count_heredoc(prompt);
	if (check_input(prompt))
		mini->fail = 1;
	else if (!expand(mini, prompt))
		mini->fail = 2;
	else if (!splitpipe(mini))
		mini->fail = 1;
	else if (!table_token_redir(mini))
		mini->fail = 1;
	if (!mini->fail)
		newheredoc(mini);
	if (!mini->fail && g_sig != 130)
		execmain(mini);
	free_minishell(mini, 0);
	mini->fail = 0;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*prompt;
	t_mini	*mini;

	mini = init_signals();
	prompt = NULL;
	((void)ac, (void)av, init_data(mini, env));
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signals();
	while (1)
	{
		prompt = readline(BLUE "Minishell$ ~~ > " RESET);
		if (!prompt)
		{
			(free_minishell(mini, 1), ft_putstr_fd("exit\n", 1));
			break ;
		}
		else if (!*prompt)
			continue ;
		(add_history(prompt), minishell(mini, prompt), free(prompt));
		if (mini->fail == 1)
			free_minishell(mini, 1);
	}
	free_minishell(mini, 1);
	return (0);
}
