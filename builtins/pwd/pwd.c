/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:35:54 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/02 17:45:44 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_builtin(t_mini *mini, t_token token)
{
	char	*pwd;

	(void)mini;
	(void)token;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		ft_printf("%s\n", pwd);
		free(pwd);
		pwd = NULL;
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("chdir: error retrieving current directory :"
			"getcwd: cannot access parent directories:"
			" No such file or directory\n",
			1);
		return (EXIT_FAILURE);
	}
}
