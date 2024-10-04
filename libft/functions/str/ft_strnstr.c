/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:07 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:03:07 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//searches for the first occurrence of a substring (needle) within a
//given string (haystack) up to a specified length
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	if ((haystack == NULL || needle == NULL) && !len)
		return (NULL);
	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == '\0')
		return (h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (h[i + j] != '\0' && i + j < len && h[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return (&h[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("Original: %s\n", strstr("Comment tu t'appelles ?", "tu"));
// 	printf("Result: %s\n", ft_strnstr("Comment tu t'appelles ?", "tu", 18));
// 	return (0);
// }
