/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:05:57 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//calculate the len of the hexadecimal representation of an unsigned integer nbr
size_t	ft_hex_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

//prints the hexa representation of unsigned int nbr with the specified format
void	ft_put_hex_format(unsigned int nbr, char format)
{
	if (nbr >= 16)
	{
		ft_put_hex_format(nbr / 16, format);
		ft_put_hex_format(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_printf_putchar_fd(nbr + '0', 1);
		else
		{
			if (format == 'x')
				ft_printf_putchar_fd(nbr - 10 + 'a', 1);
			else if (format == 'X')
				ft_printf_putchar_fd(nbr - 10 + 'A', 1);
		}
	}
}

//prints the hexadecimal representation of an unsigned integer with the
//specified format and returns the length of the representation
size_t	ft_put_hex(unsigned int nbr, char format)
{
	if (nbr == 0)
		return (ft_printf_putchar_fd('0', 1));
	else
		ft_put_hex_format(nbr, format);
	return (ft_hex_len(nbr));
}

// #include <stdio.h>
// int main()
// {
// 	unsigned int	number = 154;
// 	size_t			len;

// 	// Print hexadecimal representation in lowercase (format 'x')
// 	len = ft_put_hex(number, 'x');
// 	printf("\nLength: %zu\n", len);

// 	// Print hexadecimal representation in uppercase (format 'X')
// 	len = ft_put_hex(number, 'X');
// 	printf("\nLength: %zu\n", len);

// 	return (0);
// }
