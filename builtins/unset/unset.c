/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:52 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 14:08:35 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset_builtin(t_mini *mini, char **var_names)
{
	char	**new_env;
	char	**tmp;
	int		i;

	if (!var_names || !mini->env_tab)
		return (ERROR);
	i = 0;
	while (var_names[i])
	{
		if (var_names[i] && mini->env_tab)
		{
			new_env = unset_env_var(var_names[i], mini->env_tab);
			if (new_env)
			{
				tmp = mini->env_tab;
				mini->env_tab = new_env;
				free_array(tmp);
			}
			else
				error_msg("unset", "Failed to unset variable", 1);
		}
		i++;
	}
	return (g_sig = 0, SUCCESS);
}
