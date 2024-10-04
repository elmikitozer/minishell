/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:24 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 14:53:24 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//clears a linked list by deleting all nodes and setting the head ptr to NULL
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}

/*
1. Check if either the list pointer or the del functiion is NULL
2. Loop through the list and delete each node
	- Save the next node in the list
	- Delete the current node using the provided delete function
	- Move to the next node
3. Set the list pointer to NULL after clearing the list
*/