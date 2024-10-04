/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:55:53 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/04 17:20:00 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	changepwd_env(t_mini *mini)
{
	char	*pwd_env;
	char	*pwd;
	int		i;

	i = -1;
	pwd = getcwd(NULL, 0);
	pwd_env = ft_strjoin("PWD=", pwd);
	(free(pwd), pwd = NULL);
	if (!pwd_env)
		error_exit(mini, "cd", "malloc failed", 1);
	while (mini->env_tab[++i])
	{
		if (!ft_strncmp(mini->env_tab[i], "PWD=", ft_strlen("PWD=")))
		{
			(free(mini->env_tab[i]), mini->env_tab[i] = NULL);
			mini->env_tab[i] = pwd_env;
		}
		if (!mini->env_tab[i])
			return (0);
	}
	return (1);
}

int	updatepath(t_mini *mini)
{
	int		i;
	char	*tab;
	char	*get_cwd;

	i = -1;
	get_cwd = getcwd(NULL, 0);
	if (!get_cwd)
		return (ft_putstr_fd(ERR_CHDIR, 1), g_sig = 1, 0);
	while (mini->env_tab[++i])
	{
		if (!ft_strncmp(mini->env_tab[i], "OLDPWD=", ft_strlen("OLDPWD=")))
		{
			tab = ft_strjoin("OLDPWD=", get_cwd);
			if (!tab)
				return (error_exit(mini, "cd", "malloc failed", 1), 0);
			(free(mini->env_tab[i]), mini->env_tab[i] = NULL);
			mini->env_tab[i] = tab;
			((free(get_cwd)), get_cwd = NULL);
			if (!mini->env_tab[i])
				return (0);
		}
	}
	return (free(get_cwd), get_cwd = NULL, 1);
}

// Utility function to update OLDPWD and change directory
int	cd_and_update(t_mini *mini, const char *path)
{
	if (!updatepath(mini))
		return (ERROR);
	if (chdir(path) == -1)
	{
		perror("minishell: cd");
		g_sig = 1;
		return (ERROR);
	}
	return (SUCCESS);
}

// Utility function to expand '~' to home directory and change directory
int	expand_and_cd(t_mini *mini, const char *path)
{
	char	*expanded_path;

	expanded_path = ft_strjoin(find_env_var(mini->env_tab, "HOME"), (char *)path
			+ 1);
	if (!expanded_path)
		return (error_exit(mini, "cd", "malloc failed", 1), ERROR);
	if (cd_and_update(mini, expanded_path) == ERROR)
		return (free(expanded_path), ERROR);
	free(expanded_path);
	return (changepwd_env(mini));
}
