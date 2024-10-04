/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:10 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:03:10 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//searches for the last occurrence of a specific character in a given string
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	value;
	char	*str;

	len = ft_strlen(s);
	value = (char)c;
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == value)
			return (&str[len]);
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("Original: %s\n", strrchr("Salade tomates sauce samouraiii", 'a'));
// 	printf("Result: %s\n", ft_strrchr("Salade tomates sauce samouraiii", 'a'));
// 	return (0);
// }
