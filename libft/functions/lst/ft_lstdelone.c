/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:01:55 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:01:55 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//deletes a single node from a linked list
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del (lst->content);
	free (lst);
}

/*
1. Check if either the list pointer or the del functiion is NULL
2. Call the delete function to free any data associated with the node
3. Free the memory of the node itself
*/