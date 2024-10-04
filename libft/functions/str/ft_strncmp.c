/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:04 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:03:04 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//compares two strings up to a specified number of characters
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && (i < n - 1))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("Original: %d\n", strncmp("Bonjour", "Boojour", 100));
// 	printf("Result: %d\n", ft_strncmp("Bonjour", "Boojour", 100));
// 	return (0);
// }
