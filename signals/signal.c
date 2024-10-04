/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:38:15 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 11:52:07 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	backslash(int sig)
{
	if (sig == SIGQUIT)
		g_sig = 131;
	else if (sig == SIGINT)
	{
		g_sig = 130;
		write(1, "\n", 1);
	}
}

void	ctrlchd(int sig)
{
	if (sig == SIGINT)
	{
		g_sig = EXEC_CTRL_C;
		close(STDIN_FILENO);
		return ;
	}
}

void	ctrlc(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_sig = 130;
	}
}

void	ctrlcp(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
		g_sig = 130;
	}
}

t_mini	*init_signals(void)
{
	static t_mini	mini;

	return (&mini);
}
