/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:07 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 13:51:43 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Extract/Get the name of env variable
@param arg -> "NAME=value" format
@param len -> +1 for '\0'

@return name-> extracted name of env variable
*/
char	*get_env_name(char *arg)
{
	char	*name;
	size_t	len;

	len = 0;
	if (ft_strncmp(arg, "_=", 2) == 0)
		return (NULL);
	if (ft_strncmp(arg, "=", 1) == 0)
		return (ft_strdup("="));
	else if (!ft_strchr(arg, '='))
		len = ft_strlen(arg) + 1;
	else
		len += ft_strchr(arg, '=') - arg + 1;
	name = ft_calloc(len, sizeof(char));
	if (!name)
		exit(EXIT_FAILURE);
	ft_strlcpy(name, arg, len);
	return (name);
}

/* Get value of env variable
@param arg -> "NAME=value" format
@param len -> +1 for '\0'
@param strlcpy -> copies up to len-1 characters from ptr

@return value-> extracted value of env variable
*/
char	*get_env_value(char *arg)
{
	char	*ptr;
	char	*value;
	size_t	len;

	ptr = ft_strchr(arg, '=');
	if (!ptr)
		return (NULL);
	ptr++;
	len = ft_strlen(ptr) + 1;
	value = ft_calloc(len, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	ft_strlcpy(value, ptr, len);
	return (value);
}
