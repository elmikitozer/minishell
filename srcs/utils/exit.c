/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:16 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/02 12:07:39 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_minishell(t_mini *mini)
{
	if (errno != EXIT_SUCCESS)
		error_msg("minishell: ", NULL, errno);
	free_minishell(mini, 1);
	rl_clear_history();
	exit(g_sig);
}
