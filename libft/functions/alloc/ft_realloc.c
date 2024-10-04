/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:39:50 by gchenot           #+#    #+#             */
/*   Updated: 2024/05/02 16:44:02 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_realloc(void *ptr, size_t current_size, size_t new_size)
{
	char	*new_ptr;

	if (ptr == 0)
		return (malloc(new_size));
	if (new_size <= current_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, current_size);
	free(ptr);
	return (new_ptr);
}

// void	*ft_realloc(void *ptr, size_t new_size)
// {
// 	char	*new_ptr;
// 	size_t	current_size;

// 	if (ptr == 0)
// 		return (malloc(new_size));
// 	current_size = sizeof(ptr);
// 	if (new_size <= current_size)
// 		return (ptr);
// 	new_ptr = malloc(new_size);
// 	ft_memcpy(ptr, new_ptr, current_size);
// 	free(ptr);
// 	return (new_ptr);
// }
