/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:00 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/05 14:33:56 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

static int	check_exit_atol(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	res = 0;
	if (!str || *str == '\0')
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = check_sign(str, &i);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > LLONG_MAX) || (sign == -1
				&& res > (unsigned long long)LLONG_MAX + 1))
			return (0);
		i++;
	}
	return (1);
}

static long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = check_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (LLONG_MAX / 10) || (res == LLONG_MAX / 10 && (str[i]
					- '0') > (LLONG_MAX % 10)))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	exit_builtin(t_mini *mini, t_token token)
{
	int	ac;

	ac = token.args_count;
	if (ac > 1 && !check_exit_atol(token.args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(token.args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		(free_minishell(mini, 1), exit(2));
	}
	else if (ac > 2)
	{
		error_msg("exit", "too many arguments", 1);
		return ;
	}
	ft_printf("exit\n");
	if (ac == 1)
		(free_minishell(mini, 1), exit(g_sig));
	if (token.args[1])
		ac = ft_atoll(token.args[1]);
	(free_minishell(mini, 1), exit(ac));
}
