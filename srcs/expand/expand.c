/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:08:56 by myevou            #+#    #+#             */
/*   Updated: 2024/09/06 17:03:22 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expandexitcode(t_inputexpand *input, int i, int *j)
{
	int		jdex;
	char	*value;
	bool	valuefound;

	valuefound = 0;
	i++;
	jdex = *j;
	value = ft_itoa(g_sig);
	if (!value)
		return (ft_printf("minishell: malloc failed\n"), 0);
	else
	{
		valuefound = 1;
		while (*value)
			input->new[jdex++] = *value++;
	}
	while (*value)
		input->new[jdex++] = *value++;
	if (valuefound)
		free(&value[-jdex + *j]);
	*j = jdex;
	return (i);
}

int	expanding(t_inputexpand *input, int i, int *j, int lentotal)
{
	int		lenkey;
	char	c;
	char	*value;
	int		jdex;

	jdex = *j;
	if (dollarquote(input, i, j, lentotal))
		return (i + 1);
	i++;
	if (input->str[i] == '?')
		return (expandexitcode(input, i, j));
	lenkey = lenofkey(&input->str[i]);
	c = input->str[i + lenkey];
	input->str[i + lenkey] = '\0';
	value = getvaluefromkey(&input->str[i], input->env);
	if (value)
	{
		while (*value)
			input->new[jdex++] = *value++;
	}
	i += lenkey;
	input->str[i] = c;
	*j = jdex;
	return (i);
}

char	*newstring(int lentotal, char *str, char **env)
{
	int				i;
	int				j;
	t_inputexpand	input;

	i = 0;
	j = 0;
	if (!initinput(&input, str, env, lentotal))
		return (ft_printf("Fail to init new (malloc)"), NULL);
	while (input.str[i])
	{
		quotetype(&input, i);
		while (input.str[i] && input.str[i] == '$')
		{
			if (input.str[i + 1] && (input.str[i + 1] != ' ')
				&& input.str[i + 1] != '+' && input.str[i + 1] != '/')
				i = expanding(&input, i, &j, lentotal);
			else
				input.new[j++] = input.str[i++];
			quotetype(&input, i);
		}
		if (str[i] && str[i] != '$')
			input.new[j++] = str[i++];
	}
	input.new[j] = 0;
	return (input.new);
}

int	expand(t_mini *mini, char *str)
{
	int	lentotale;

	lentotale = lentotal(str, mini->env_tab) + 2;
	if (check_quotes_exp(str))
	{
		mini->input = newstring(lentotale, str, mini->env_tab);
		reverse_quotes(mini->input);
		if (!mini->input)
		{
			mini->fail = 1;
			return (0);
		}
	}
	else
	{
		reverse_quotes(str);
		ft_printf("Minishell: Quotes are not closed\nIn input : %s\n", str);
		return (0);
	}
	return (1);
}

char	*expand_hd(t_mini *mini, char *str)
{
	int		lentotale;
	char	*output;

	lentotale = lentotal(str, mini->env_tab) + 2;
	output = str;
	output = newstring(lentotale, str, mini->env_tab);
	(free(str), str = NULL);
	if (!output)
	{
		mini->fail = 1;
		return (0);
	}
	return (output);
}
