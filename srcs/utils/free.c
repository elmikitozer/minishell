/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:26:27 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 11:09:56 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tokens(t_token *tk, int count)
{
	int	i;

	i = 0;
	if (tk && count)
	{
		while (i < count)
		{
			if (tk[i].args)
				ft_freetab(tk[i].args);
			if (tk[i].filename)
				ft_freetab(tk[i].filename);
			if (tk[i].redir)
				free(tk[i].redir);
			i++;
		}
		free(tk);
	}
}

void	free_env_elem(t_env *env)
{
	if (env->name)
		free(env->name);
	if (env->value)
		free(env->value);
}

void	free_env(t_env **env)
{
	t_env	*ptr;

	while (*env)
	{
		ptr = *env;
		*env = (*env)->next;
		free_env_elem(ptr);
		free(ptr);
	}
}

void	free_cmd(t_commands **cmd)
{
	t_commands	*ptr;

	while (*cmd)
	{
		ptr = *cmd;
		*cmd = (*cmd)->next;
		if (ptr->args)
			ft_freetab(ptr->args);
		if (ptr->str)
			(free(ptr->str), ptr->str = NULL);
		free(ptr);
	}
}

void	free_minishell(t_mini *mini, int fenv)
{
	if (mini->env_tab && fenv)
		(ft_freetab(mini->env_tab), mini->env_tab = NULL);
	if (mini->envpath)
		(ft_freetab(mini->envpath), mini->envpath = NULL);
	if (mini->cmd_path)
		(ft_freetab(mini->cmd_path), mini->cmd_path = NULL);
	if (mini->inputpipesplited)
		(ft_freetab(mini->inputpipesplited), mini->inputpipesplited = NULL);
	if (mini->hdocs != NULL && fenv == 2)
		(free_hdocs(mini->hdocs), mini->hdocs = NULL);
	if (mini->delim && fenv == 2)
		(ft_freetab(mini->delim), mini->delim = NULL);
	if (mini->input)
		(free(mini->input), mini->input = NULL);
	if (mini->redir)
		(free(mini->redir), mini->redir = NULL);
	if (mini->cmd)
		(free(mini->cmd), mini->cmd = NULL);
	if (mini->pipe_nb)
		(free_tokens(mini->token, mini->pipe_nb), mini->token = NULL);
	(free_cmd(&mini->cmd_str), mini->cmd_str = NULL);
	(free_env(&mini->env), mini->env = NULL);
}
