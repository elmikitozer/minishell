/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:15:51 by myevou            #+#    #+#             */
/*   Updated: 2024/09/05 14:21:31 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	dollarquote(t_inputexpand *input, int i, int *j, int lentotal)
{
	int	jdex;

	jdex = *j;
	if ((input->str[i + 1] == '\"' && input->quotetype != 0) || (input->str[i
				+ 1] == '\'' && input->quotetype == '\"'))
	{
		input->new = ft_realloc(input->new, lentotal + 1, lentotal + 100);
		input->new[jdex++] = input->str[i++];
		*j = jdex;
		return (1);
	}
	return (0);
}
