/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:11 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//converts the unsigned integer n to a string for output
size_t	ft_put_unsigned(unsigned int n)
{
	size_t	len;
	char	*nbr;

	if (n == 0)
		return (ft_printf_putchar_fd('0', 1));
	nbr = ft_uitoa(n);
	len = ft_printf_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

// int main()
// {
// 	ft_put_unsigned(12345); //Output: 12345
// 	return 0;
// }
