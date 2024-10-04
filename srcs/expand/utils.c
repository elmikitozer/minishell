/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:07:55 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 10:57:41 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*getvaluefromkey(char *str, char **env)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(str, env[i], len) && env[i][len] == '=')
			return (&env[i][len + 1]);
		i++;
	}
	return (NULL);
}

int	initinput(t_inputexpand *input, char *str, char **env, int lentotal)
{
	input->len = 0;
	input->lenkey = 0;
	input->quotetype = 0;
	input->str = str;
	input->env = env;
	input->new = malloc(lentotal + 100);
	if (!input->new)
		return (0);
	return (1);
}

int	check_quotes_exp(char *str)
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
			if (quote == '\'')
				str[i] *= -1;
			i++;
		}
	}
	return (!quote);
}

void	reverse_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
			str[i] *= -1;
		i++;
	}
}

void	quotetype(t_inputexpand *input, int i)
{
	if (input->str[i] == '\'' && !input->quotetype)
		input->quotetype = '\'';
	else if (input->str[i] == '\"' && !input->quotetype)
		input->quotetype = '\"';
	else if (input->str[i] == input->quotetype)
		input->quotetype = 0;
}
