/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:17 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:17 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//compares two blocks of memory
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}

// 	#include <stdio.h>
// 	#include <string.h>
// int	main(void)
// {
// 	printf("Original: %d\n", memcmp("Bonjour", "Bozjour", 8));
// 	printf("Result: %d\n", ft_memcmp("Bonjour", "Bozjour", 8));
// 	return (0);
// }
