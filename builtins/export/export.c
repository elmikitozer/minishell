/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:57 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/10 10:59:32 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	free_export(char *name, char *value, int status)
{
	g_sig = 1;
	if (name)
		(free(name), name = NULL);
	if (value)
		(free(value), value = NULL);
	return (status);
}

static void	check_name_value(char *name, char *value, char *args, int *freed)
{
	if ((!ft_strcmp(name, "_")) && (!value || ft_strcmp(value, "") == 0))
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(args, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		*freed = free_export(name, value, 1);
	}
	else if (ft_strchr(name, '-') || (!ft_isalpha(name[0]) && name[0] != '_'))
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(args, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		*freed = free_export(name, value, 1);
	}
	else if (!value)
		value = ft_strdup("");
}

int	handle_export_argument(t_mini *mini, t_token token, int i)
{
	char	*name;
	char	*value;
	char	**new_env;
	int		freed;

	name = NULL;
	freed = 0;
	name = get_env_name(token.args[i]);
	if (!name)
		return (ERROR);
	value = get_env_value(token.args[i]);
	check_name_value(name, value, token.args[i], &freed);
	if (freed != 1)
	{
		new_env = set_env_var(name, value, mini->env_tab);
		if (new_env && ft_strchr(token.args[i], '='))
			(free_array(mini->env_tab), mini->env_tab = new_env);
		(free(name), free(value));
	}
	return (SUCCESS);
}

int	export_builtin(t_mini *mini, t_token token)
{
	int	i;

	i = 1;
	g_sig = 0;
	if (!token.args[1])
		return (env_builtin(mini, token));
	while (token.args[i])
	{
		if (ft_strcmp(token.args[i], "-A") == 0)
			return (ft_printf("\n"), g_sig = 0, SUCCESS);
		if (token.args[i][0] == '-')
		{
			return (error_msg(token.args[i], "export: invalid option", 1),
				g_sig = 2, ERROR);
		}
		else if (handle_export_argument(mini, token, i) == ERROR)
			return (error_msg(token.args[i], "export: not a valid identifier",
					1), g_sig = 1, ERROR);
		i++;
	}
	return (SUCCESS);
}
