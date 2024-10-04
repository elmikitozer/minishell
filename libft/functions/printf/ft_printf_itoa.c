/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:01 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//calculates the length of the number by counting the digits
static size_t	ft_number_len(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

//converts an integer to a dynamically allocated string
char	*ft_itoa(int n)
{
	size_t	i;
	size_t	nb_len;
	long	nb;
	char	*str;

	nb_len = ft_number_len(n);
	nb = (long)n;
	str = malloc(sizeof(char) * (nb_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nb == 0)
		str[i] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[(nb_len - 1) - i++] = nb % 10 + '0';
		nb /= 10;
	}
	str[nb_len] = 0;
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(0));
//  return(0);
// }
