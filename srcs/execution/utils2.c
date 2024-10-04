/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:05:10 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 14:00:09 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fdargs(t_args *args, int i)
{
	close(args->fd[1]);
	if (i)
		close(args->old_pipes);
	args->old_pipes = args->fd[0];
}

void	tk_argsflags(t_args *args, int redir)
{
	if (redir == 2)
		args->flag = O_APPEND;
	else
		args->flag = O_TRUNC;
}
