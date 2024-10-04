/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:12:22 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 15:00:49 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quotes(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else if ((str[i] == '\'' || str[i] == '\"') && !quote)
			quote = str[i++];
		else
		{
			if (quote != 0)
				str[i] *= -1;
			i++;
		}
	}
	return (!quote);
}

void	inchev(const char *s, size_t *words, bool *inword, int *i)
{
	if (s[*i + 1] && s[*i] == s[*i + 1])
		*i += 1;
	*words += 1;
	*inword = 0;
}

void	isinword(bool *inword, size_t *words)
{
	if (!*(inword))
	{
		*words += 1;
		*inword = 1;
	}
}

int	splitpipe(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->fail)
		return (0);
	if (check_quotes(mini->input))
	{
		mini->inputpipesplited = ft_split(mini->input, '|');
		if (!mini->inputpipesplited)
			return (ft_printf ("minishell: malloc failed\n"), 0);
		while (mini->inputpipesplited[i])
		{
			reverse_quotes(mini->inputpipesplited[i]);
			i++;
		}
	}
	else
		return (printf("Quotes are not closed\n"), 0);
	mini->pipe_nb = i;
	return (1);
}
