/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitsep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:17:07 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 14:15:12 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	count_wordssplitsep(char const *s, char c, char *sep)
{
	size_t	words;
	bool	inword;
	int		i;

	words = 0;
	inword = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c || ((c == ' ') && (s[i] >= '\t') && (s[i] <= '\r')))
			inword = 0;
		else if (s[i] == sep[0] || s[i] == sep[1])
			inchev(s, &words, &inword, &i);
		else
			isinword(&inword, &words);
		i++;
	}
	return (words);
}

void	fill_tab(char *new, char const *s, char c, char *sep)
{
	size_t	i;

	i = 0;
	if (s[i] == sep[0])
	{
		new[i++] = sep[0];
		if (s[i] == sep[0])
			new[i++] = sep[0];
	}
	else if (s[i] == sep[1])
	{
		new[i++] = sep[1];
		if (s[i] == sep[1])
			new[i++] = sep[1];
	}
	else
	{
		while (s[i] && s[i] != c && s[i] != sep[0] && s[i] != sep[1])
		{
			new[i] = s[i];
			i++;
		}
	}
	new[i] = '\0';
}

size_t	findcount(const char *s, size_t index, char c, char *sep)
{
	size_t	count;

	count = 0;
	if (s[index + count] == sep[0])
	{
		if (s[index + count + 1] == sep[0])
			count = 2;
		else
			count = 1;
	}
	else if (s[index + count] == sep[1])
	{
		if (s[index + count + 1] == sep[1])
			count = 2;
		else
			count = 1;
	}
	else
	{
		while (s[index + count] && s[index + count] != c && s[index
				+ count] != sep[0] && s[index + count] != sep[1])
			count++;
	}
	return (count);
}

int	set_mem(char **tab, char const *s, char c, char *sep)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		while (((c == ' ') && (s[index] >= '\t')
				&& (s[index] <= '\r')))
			index++;
		count = findcount(s, index, c, sep);
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return (1);
			(fill_tab(tab[i], (s + index), c, sep), i++);
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
	return (0);
}

char	**ft_splitseparator(char const *s, char c, char *sep)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_wordssplitsep(s, c, sep);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	if (set_mem(tab, s, c, sep))
	{
		ft_freetab(tab);
		return (NULL);
	}
	return (tab);
}
