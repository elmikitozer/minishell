/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:14 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//output a character to a specified file descriptor
size_t	ft_printf_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (-1);
	write(fd, &c, 1);
	return (1);
}

// int main(void)
// {
// 	int fd;

// 	fd = 1;
// 	 ft_putchar_fd('G', fd);
// 	 return (0);
// }
