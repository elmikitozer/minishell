/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:42:57 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 11:57:19 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	token(char **tab, t_token *tk)
{
	int	i;
	int	a;
	int	r;

	i = 0;
	a = 0;
	r = 0;
	while (tab[i])
	{
		if (isaredirection(tab[i]))
		{
			tk->redir[r] = isaredirection(tab[i++]);
			if (!tab[i])
			{
				tk->fail = 1;
				return ;
			}
			tk->filename[r] = ft_strdup(remove_quote(tab[i]));
			r++;
		}
		else
			tk->args[a++] = ft_strdup(remove_quote(tab[i]));
		i++;
	}
	tk->cmd = tk->args[0];
}

char	*remove_quote(char *str)
{
	int	i;
	int	j;
	int	in_quote;

	i = -1;
	j = 0;
	in_quote = 1;
	while (str[++i])
	{
		if ((str[i] == '\'' || str[i] == '\"'))
		{
			in_quote = !str[i];
			if (str[i + 1] && str[i + 1] == str[i])
			{
				i++;
				in_quote = 0;
			}
		}
		else
			str[j++] = str[i];
	}
	if ((j > 0) && ((str[j - 1] == '\'') || str[j - 1] == '\"') && !in_quote)
		j--;
	str[j] = 0;
	return (str);
}

t_token	redir(char *input)
{
	char	**tab;
	t_token	tk;
	int		i;

	i = 0;
	init_token(&tk);
	check_quotes(input);
	tab = ft_splitseparator(input, ' ', "><");
	if (!tab)
		return (tk);
	while (tab[i])
	{
		reverse_quotes(tab[i]);
		i++;
	}
	tokensize(tab, &tk);
	token(tab, &tk);
	ft_freetab(tab);
	return (tk);
}

int	table_token_redir(t_mini *mini)
{
	int	i;

	mini->token = malloc(sizeof(t_token) * mini->pipe_nb);
	if (!mini->token)
		return (ft_printf("minishell: malloc failed\n"), 0);
	i = -1;
	while (++i < mini->pipe_nb)
	{
		mini->token[i] = redir(mini->inputpipesplited[i]);
		if (mini->token[i].fail)
		{
			ft_printf(ER_TK);
			return (0);
		}
	}
	return (1);
}
