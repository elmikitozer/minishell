/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:24 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//converts an unsigned integer to a dynamically allocated string representation
char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	char	*nbr;

	len = ft_nbr_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}

// #include <stdio.h>
// int main()
// {
// 	 unsigned int num = 12345;
// 	 char *str = ft_uitoa(num);
// 	 if (str)
// 	 {
// 		 printf("Number: %u, String: %s\n", num, str);		//Output: "12345"
// 		 free(str);
// 	 }
// 	 return 0;
// }
