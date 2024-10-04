/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:08:06 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 12:32:18 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_doublepipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			if (str[i + 1] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int	space_check(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
			j++;
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

int	check_input(char *str)
{
	if (check_quotes(str))
	{
		if (space_check(str))
			return (1);
		if (check_doublepipe(str))
		{
			ft_putstr_fd("minishell: syntax error near"
				" unexpected token `||'\n", 2);
			return (1);
		}
		reverse_quotes(str);
		return (0);
	}
	else
	{
		ft_putstr_fd("minishell: syntax error "
			"quotes not closed\n", 2);
		return (1);
	}
}
