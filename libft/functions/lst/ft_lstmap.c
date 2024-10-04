/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:02:06 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:02:06 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//creates a new list resulting from applying a function f to each element
//of the input list lst
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}

/*
1. Check if either the input list, mapping function, or delete function is NULL
2. Initialize the result list to NULL
3. Iterate through the input list
	- Apply the function to the content of the current node
	- If malloc failed clear the result list
	- Add the new node to the back of the result list
	- Move to the next nodes in both the input and result lists
4. Return a pointer to the head of the result list
*/
