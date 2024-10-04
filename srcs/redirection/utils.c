/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:42:32 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 11:58:06 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_token(t_token *tk)
{
	tk->cmd = NULL;
	tk->args = NULL;
	tk->filename = NULL;
	tk->redir = NULL;
	tk->fail = 0;
	tk->args_count = 0;
	tk->redir_count = 0;
}

void	tokensize(char **tab, t_token *tk)
{
	int	i;
	int	a;
	int	r;

	a = 0;
	i = 0;
	r = 0;
	while (tab[i])
	{
		check_quotes(tab[i]);
		if (isaredirection(tab[i]))
		{
			reverse_quotes(tab[i++]);
			r++;
		}
		else
			a++;
		if (tab[i])
			i++;
	}
	tk->redir = ft_calloc(r + 1, sizeof(int));
	tk->filename = ft_calloc(r + 1, sizeof(char *));
	tk->args = ft_calloc(a + 1, sizeof(char *));
	tk->args_count = a;
	tk->redir_count = r;
}

int	isaredirection(char *str)
{
	if (str[0] == '>')
	{
		if (str[1])
			return (2);
		else
			return (1);
	}
	else if (str[0] == '<')
	{
		if (str[1])
			return (-2);
		else
			return (-1);
	}
	return (0);
}
