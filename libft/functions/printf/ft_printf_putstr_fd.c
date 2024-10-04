/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:21 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//output a string to a specified file descriptor
size_t	ft_printf_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str || fd < 0)
	{
		ft_printf_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	char str[] = "Hello, World!\n";
// 	int fd = 1;

// 	printf("Output length: %zu\n", ft_printf_putstr_fd(str, fd));
// 	return 0;
// }
