/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:15 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:15 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//searches for the first occurrence of a specific byte value in a memory block
//unsigned char ensures that operations are performed on a byte-by-byte basis
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*str;

	i = 0;
	value = (unsigned char) c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == value)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("Original: %p\n", memchr("Bonjour", 'n', 5));
// 	printf("Result: %p\n", ft_memchr("Bonjour", 'n', 5));
// 	return (0);
// }
