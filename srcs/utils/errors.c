/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:02:56 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/02 12:08:32 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*  Prints error messages to the standard error stream STDERR

@param exe -> name of the executable or command where the error occurred
@param file -> file associated with the error, e.g. filename or filepath
@param err -> an error code or errno associated with the error
@param error -> a custom error message

@return nada
*/
int	error_msg(char *exe, char *err_msg, int exit_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (exe)
	{
		ft_putstr_fd(exe, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_sig = exit_code;
	return (exit_code);
}

void	error_exit(t_mini *mini, char *exe, char *err_msg, int exit_code)
{
	error_msg(exe, err_msg, exit_code);
	free_minishell(mini, 1);
	exit(exit_code);
}
