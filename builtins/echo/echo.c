/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:06 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/02 19:13:32 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Check if -n option
@param n_flag-> Returns 1 if arg is some variation of -n, -nn, -nnnn...
Returns 0 if it contains anything other than - and n (ex. --n -nnnm -n1234)

@return return status is always 0.
*/
int	check_nflag(char *arg)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	if (arg[i] != 'n')
		return (0);
	while (arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = 1;
	return (n_flag);
}

/* Built-in for echo function with -n option
@param args -> arguments
@param n_flag-> Returns 1 if arg is some variation of -n, -nn, -nnnn...
Returns 0 if it contains anything other than - and n (ex. --n -nnnm -n1234)

@return return status is always 0.
*/
void	echo_builtin(char **args)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (args[i] && check_nflag(args[i]))
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!n_flag)
		ft_printf("\n");
	g_sig = 0;
}
