/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_uintptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:09 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//calculates len of the hexadecimal representation of an unsigned long long int
size_t	ft_uintptr_len(unsigned long long nbr)
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

//print the hexadecimal representation of an unsigned long long integer
void	ft_put_uintptr_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_uintptr_hex(nbr / 16);
		ft_put_uintptr_hex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_printf_putchar_fd(nbr + '0', 1);
		else
			ft_printf_putchar_fd(nbr - 10 + 'a', 1);
	}
}

/*
print the hexadecimal representation of an unsigned long long integer (ptr)
along with the "0x" prefix
len is the sum of the length of "0x" and the len of the hexa representation*/
size_t	ft_put_uintptr(unsigned long long ptr)
{
	size_t	len;

	if (ptr == 0)
		return (ft_printf_putstr_fd("(nil)", 1));
	len = ft_printf_putstr_fd("0x", 1);
	ft_put_uintptr_hex(ptr);
	len += ft_uintptr_len(ptr);
	return (len);
}

// #include <stdio.h>
// #include "ft_printf.h"
// int main()
// {
// 	 unsigned long long testPointer = 0x123456789ABC;

// 	 printf("Hexadecimal representation: \n");
// 	 size_t len = ft_put_uintptr(testPointer);
// 	 printf("\nLength of hexadecimal representation: %zu\n", len);
// 	 return 0;
// }
