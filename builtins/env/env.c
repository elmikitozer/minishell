/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:03 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/04 15:15:43 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_builtin(t_mini *mini, t_token token)
{
	int	i;

	i = 0;
	if (token.args_count > 2)
	{
		ft_printf("env: too many arguments\n");
		return (ERROR);
	}
	if (mini->env_tab)
	{
		while (mini->env_tab[i])
			ft_printf("%s\n", mini->env_tab[i++]);
	}
	return (g_sig = 0, SUCCESS);
}
