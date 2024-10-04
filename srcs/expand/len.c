/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:04:20 by myevou            #+#    #+#             */
/*   Updated: 2024/09/02 12:35:10 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lenofkey(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (1);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	inoutquotelen(char *str, int i, int *len)
{
	if (str[i] == '\'')
	{
		i++;
		(*len)++;
		while (str[i] && str[i] != '\'')
		{
			i++;
			(*len)++;
		}
	}
	return (i);
}

int	expandlen(char *str, int i, int *len, char **env)
{
	int		lenkey;
	char	c;
	char	*value;
	char	*lenstatus;

	i++;
	if (str[i] == '?')
	{
		lenstatus = ft_itoa(g_sig);
		i++;
		(*len) += ft_strlen(lenstatus);
		free(lenstatus);
		return (i);
	}
	lenstatus = NULL;
	lenkey = lenofkey(&str[i]);
	c = str[i + lenkey];
	str[i + lenkey] = '\0';
	value = getvaluefromkey(&str[i], env);
	if (value)
		*len += ft_strlen(value);
	i += lenkey;
	str[i] = c;
	return (i);
}

int	lentotal(char *str, char **env)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == '$')
			i = expandlen(str, i, &len, env);
		if (str[i])
		{
			i++;
			len++;
		}
	}
	return (len);
}
