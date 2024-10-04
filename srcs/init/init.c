/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:02:52 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 13:49:12 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			(free(tab[i]), tab[i] = NULL);
		free(tab);
	}
}

int	copy_env(t_mini *mini, char **env)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (env[count])
		count++;
	mini->env_tab = (char **)malloc((count + 1) * sizeof(char *));
	if (!mini->env_tab)
	{
		ft_printf("Failed to allocate memory");
		return (0);
	}
	while (++i < count)
	{
		mini->env_tab[i] = ft_strdup(env[i]);
		if (!mini->env_tab[i])
		{
			perror("Failed to allocate memory for environment variable");
			ft_freetab(mini->env_tab);
		}
	}
	mini->env_tab[i] = 0;
	return (1);
}

void	initargs(t_mini *mini, t_args *args)
{
	args->nbcmds = mini->pipe_nb;
	args->env = mini->env_tab;
	args->envp = mini->env_tab;
	args->old_pipes = -1;
}

void	init_data(t_mini *mini, char **env)
{
	mini->env = NULL;
	mini->cmd_path = NULL;
	mini->cmd_str = NULL;
	mini->cmd = NULL;
	mini->input = NULL;
	mini->inputpipesplited = NULL;
	mini->redir = NULL;
	mini->envpath = NULL;
	mini->env_tab = NULL;
	mini->hdocs = NULL;
	mini->delim = NULL;
	mini->pipe_nb = 0;
	mini->fail = 0;
	mini->here_doc = 0;
	g_sig = 0;
	if (!copy_env(mini, env))
		ft_printf("Failed to copy env");
}
