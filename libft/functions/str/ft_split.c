/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:39 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/17 12:34:39 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//splits a given string into an array of strings based on a
//specified delimiter character c
int	countwords(const char *s, char c)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	if (!s)
		return (-1);
	if (s[i] != c && s[i])
	{
		sum++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			sum++;
		i++;
	}
	return (sum);
}

int	longword(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**free_split(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i++])
			free(strs[i]);
		free(strs);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**strs;

	strs = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!strs || !s)
		return (free_split(strs));
	i = -1;
	k = 0;
	while (++i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			strs[k] = malloc(sizeof(char) * (1 + longword(s + i, c)));
			if (!strs[k])
				return (free_split(strs));
			j = 0;
			while (s[i] != c && s[i])
				strs[k][j++] = s[i++];
			strs[k++][j] = 0;
		}
	}
	strs[k] = NULL;
	return (strs);
}

// #include <stdio.h>
// int	main(void)
// {
// 	 int i = 0;
// 	 char **tab;

// 	 tab = ft_split("bocallllcOeeeecZsaswcKoko", 'c');
// 	 while (tab[i])
// 	 {
// 		 printf("string %d : %s\n", i, tab[i]);
// 		 i++;
// 	 }
// 	 return (0);
// }
