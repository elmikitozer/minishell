/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:02:57 by gchenot           #+#    #+#             */
/*   Updated: 2024/05/23 12:08:18 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Get 2D-array length
int	strlen_tab(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

//  Free 2D arrays
void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array && array[i])
		free(array[i++]);
	free(array);
}
