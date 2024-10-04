/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:59:13 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 15:00:24 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_hd(int sig)
{
	t_mini	*mini;

	mini = init_signals();
	if (sig == SIGINT)
	{
		free_minishell(mini, 2);
		mini->fail = 1;
	}
	exit(130);
}

void	init_hd(t_mini *mini, t_hdocs *hdocs, char *delim)
{
	(void)mini;
	hdocs->delim = delim;
	hdocs->content = NULL;
	hdocs->filename = NULL;
	hdocs->filename = ft_strjoin("tmp", delim);
}

int	new_count_heredocs(t_mini *mini)
{
	int	nbheredocs;
	int	i;
	int	file;

	nbheredocs = 0;
	i = 0;
	while (i < mini->pipe_nb)
	{
		file = 0;
		while (mini->token[i].filename[file])
		{
			if (mini->token[i].redir[file] == -2)
				nbheredocs++;
			file++;
		}
		i++;
	}
	return (nbheredocs);
}

char	**get_heredoc_delimiters(t_mini *mini, int nbheredocs)
{
	char	**delims;
	int		i;
	int		d;
	int		file;

	delims = ft_calloc(sizeof(char *), nbheredocs + 1);
	i = 0;
	d = 0;
	while (i < mini->pipe_nb)
	{
		file = 0;
		while (mini->token[i].filename[file])
		{
			if (mini->token[i].redir[file] == -2)
				delims[d++] = ft_strdup(mini->token[i].filename[file]);
			file++;
		}
		i++;
	}
	return (delims);
}

void	exec_heredoc_in_child(t_mini *mini, char **delims, int nbheredocs)
{
	int	i;

	i = 0;
	signal(SIGINT, &exit_hd);
	while (i < nbheredocs)
	{
		newopenheredoc(mini, delims[i]);
		i++;
	}
	free_array(delims);
	free_minishell(mini, 1);
	exit(0);
}
