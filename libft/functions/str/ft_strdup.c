/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:47 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:47 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//duplicates a given str by malloc-ing for a new str and copying the content
char	*ft_strdup(char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] < 0)
			str[i] *= -1;
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("Original: %s\n", strdup("salut"));
// 	printf("Result: %s\n", ft_strdup("salut"));
// 	return (0);
// }
