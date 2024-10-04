/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:16 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// //calculates the length of an unsigned integer
size_t	ft_nbr_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

//convert an integer to a string and prints the len of the str
size_t	ft_printf_putnbr_fd(int nb, int fd)
{
	size_t	len;
	char	*nbr;

	nbr = ft_itoa(nb);
	len = ft_printf_putstr_fd(nbr, fd);
	free(nbr);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	int		num = 42;
// 	int		fd = 1;
// 	size_t	result;

// 	result = ft_printf_putnbr_fd(num, fd);
// 	printf("\nLength of printed string: %zu\n", result);
// 	return (0);
// }
