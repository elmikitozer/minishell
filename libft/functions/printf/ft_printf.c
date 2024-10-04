/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:00 by gchenot           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//Processes different format specifiers and their corresponding arguments
//formatting them, and outputting the formatted content
void	ft_format(va_list args, char c, size_t *len)
{
	if (c == 'c')
		*len += ft_printf_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		*len += ft_printf_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		*len += ft_put_uintptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*len += ft_printf_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		*len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*len += ft_put_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*len += ft_put_percent();
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			ft_format(args, str[i + 1], &len);
			i++;
		}
		else
		{
			ft_printf_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	res;
// // 	res = ft_printf("%%%c%%%i%%%u%%%p%%\n", 'q', 12, -12, &res);
// // 	printf("\nres = %d\n", res);
// // 	res = printf("%%%c%%%i%%%u%%%p%%\n", 'q', 12, -12, &res);
// // 	printf("\nres = %d\n", res);

// // 	res = ft_printf("%c %s %p %u %i %d %x %X %%\n", 'q', "str", &res,
// // -12, 12, 12, 12, 12);
// // 	printf("\nres = %d\n", res);
// // 	res = printf("%c %s %p %u %i %d %x %X %%\n", 'q', "str", &res,
// // -12, 12, 12, 12, 12);
// // 	printf("\nres = %d\n", res);
// 	char str[] = "";

// 	ft_printf("\nstr = %s\n", str);
// 	printf("\nstr = %s\n", str);

// 	res = ft_printf("");
// 	printf("\nres = %d\n", res);
// 	res = printf("");
// 	printf("\nres = %d\n", res);

// 	// res = ft_printf("\nnb = %d\n", 2147483648);
// 	// res = ft_printf("\nnb = %d\n", -2147483648);

// 	res = ft_printf(0);
// 	printf("\nres = %d\n", res);
// 	res = printf(0);
// 	printf("\nres = %d\n", res);

// 	res = ft_printf(NULL);
// 	printf("\nres = %d\n", res);
// 	res = printf(NULL);
// 	printf("\nres = %d\n", res);

// 	return (0);
// }
