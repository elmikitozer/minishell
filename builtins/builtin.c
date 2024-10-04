/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:17:42 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 13:51:54 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd || !*cmd)
		return (0);
	if (!ft_strncmp("cd", cmd, ft_strlen(cmd) + 1))
		return (1);
	if (!ft_strncmp("echo", cmd, ft_strlen(cmd) + 1))
		return (2);
	if (!ft_strncmp("env", cmd, ft_strlen(cmd) + 1))
		return (3);
	if (!ft_strncmp("exit", cmd, ft_strlen(cmd) + 1))
		return (4);
	if (!ft_strncmp("export", cmd, ft_strlen(cmd) + 1))
		return (5);
	if (!ft_strncmp("pwd", cmd, ft_strlen(cmd) + 1))
		return (6);
	if (!ft_strncmp("unset", cmd, ft_strlen(cmd) + 1))
		return (7);
	else
		return (0);
}

void	exec_builtin(t_mini *mini, t_args *args, int i, int j)
{
	(void)args;
	if (j == 1)
		cd_builtin(mini, mini->token[i]);
	else if (j == 2)
		echo_builtin(mini->token[i].args);
	else if (j == 3)
		env_builtin(mini, mini->token[i]);
	else if (j == 4)
		exit_builtin(mini, mini->token[i]);
	else if (j == 5)
		export_builtin(mini, mini->token[i]);
	else if (j == 6)
		pwd_builtin(mini, mini->token[i]);
	else if (j == 7)
		unset_builtin(mini, mini->token[i].args);
}
