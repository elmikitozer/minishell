/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:44 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:44 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//searches for the first occurrence of a specified character in a given string
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	value;
	char	*str;

	i = 0;
	value = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == value)
			return (&str[i]);
		i++;
	}
	if (value == '\0')
		return (&str[i]);
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("Result: %s\n", ft_strchr("Bonjour salut les gars", 'a'));
// 	return (0);
// }
