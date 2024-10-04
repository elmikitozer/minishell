/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:54 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:54 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//concatenate src onto dest while ensuring that the total length of
//the resulting string does not exceed a specified size
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	if ((dest == NULL || src == NULL) && !size)
		return (0);
	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size > destlen + 1)
	{
		while (src[i] && (destlen + i) < (size - 1))
		{
			dest[destlen + i] = src[i];
			i++;
		}
	}
	else if (size < destlen)
		return (srclen + size);
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}

// #include <stdio.h>
// int main()
// {
// 	char dest[20] = "Bankai ";
// 	const char *src = "Narutoooo";
// 	size_t size = sizeof(dest);

// 	size_t result = ft_strlcat(dest, src, size);

// 	printf("Concatenated String: %s\n", dest);
// 	printf("Result: %zu\n", result);

// 	return 0;
// }
