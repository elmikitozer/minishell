/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:45:29 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/04 17:09:47 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd_home(t_mini *mini)
{
	char	*home_path;

	home_path = find_env_var(mini->env_tab, "HOME");
	if (!updatepath(mini))
		return (ERROR);
	if (home_path)
	{
		if (chdir(home_path) == -1)
		{
			perror("minishell: cd");
			g_sig = 1;
			return (ERROR);
		}
	}
	else
	{
		printf("minishell: cd: HOME not set\n");
		g_sig = 1;
		return (ERROR);
	}
	return (changepwd_env(mini), SUCCESS);
}

int	cd_oldpwd(t_mini *mini)
{
	char	*old_path;

	old_path = ft_strdup(find_env_var(mini->env_tab, "OLDPWD"));
	if (!updatepath(mini))
		return (free(old_path), ERROR);
	if (old_path)
	{
		if (chdir(old_path) == -1)
		{
			perror("minishell: cd");
			g_sig = 1;
			(error_msg("cd", old_path, 1), free(old_path), old_path = NULL);
			return (ERROR);
		}
	}
	else
	{
		printf("minishell: cd: OLDPWD not set\n");
		g_sig = 1;
		(free(old_path), old_path = NULL);
		return (ERROR);
	}
	ft_printf("%s\n", old_path);
	(free(old_path), old_path = NULL);
	return (changepwd_env(mini), SUCCESS);
}

int	cd_builtin(t_mini *mini, t_token token)
{
	if (token.args_count == 1 || (token.args_count == 2
			&& ft_strlen(token.args[1]) == 0))
		return (cd_home(mini), SUCCESS);
	else if (token.args_count > 2)
		error_msg("cd", "too many arguments", 1);
	else if (ft_strcmp(token.args[1], "~") == 0 || ft_strncmp(token.args[1],
			"~/", 2) == 0)
		return (expand_and_cd(mini, token.args[1]));
	else if (ft_strcmp(token.args[1], "-") == 0)
		return (cd_oldpwd(mini));
	else
	{
		if (cd_and_update(mini, token.args[1]) == ERROR)
			return (ERROR);
	}
	return (changepwd_env(mini), SUCCESS);
}
