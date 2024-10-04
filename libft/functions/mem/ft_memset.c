/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:26 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:26 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//fills a block of memory with a specified byte value
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*str;

	i = 0;
	value = (unsigned char)c;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = value;
		i++;
	}
	return (b);
}
