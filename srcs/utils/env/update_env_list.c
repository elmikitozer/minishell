/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:09 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 13:51:16 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* creates a new array in which all elements from original array and new value
are copied into
@param ***array allows you to modify the pointer to an array of strings
@param value Value to assign to the environment variable

@return (void) updates original array pointer to point to the new array
*/
void	append_to_array(char ***array, char *value)
{
	size_t	i;
	size_t	size;
	char	**new_array;

	if (!array)
		return ;
	size = strlen_tab(*array) + 1;
	new_array = malloc(sizeof(char *) * (size + 1));
	if (!new_array)
		return ;
	i = 0;
	while ((*array)[i])
	{
		new_array[i] = (*array)[i];
		i++;
	}
	new_array[i++] = value;
	new_array[i] = NULL;
	free(*array);
	*array = new_array;
}

/* Add or update an env variable in an env list
@param name Name of the environment variable to set
@param value Value to assign to the environment variable
@param char_*const_*envp A read-only list of env variables

@return tmp -> new list without the variable
*/
char	**set_env_var(char *name, char *value, char **envp)
{
	char	*var_name;
	char	*full_var;
	char	**tmp;

	if (!name || !value)
		return (envp);
	var_name = ft_strjoin(name, "=");
	if (!var_name)
		return (envp);
	full_var = ft_strjoin(var_name, value);
	free(var_name);
	if (!full_var)
		return (envp);
	tmp = unset_env_var(name, envp);
	if (!tmp)
		free(full_var);
	append_to_array(&tmp, full_var);
	return (tmp);
}

/* Remove an env var from env list
@param const char *name -> name of the environment variable to remove
@param char *const *envp -> current list of environment variables

@return tmp -> new list without the variable
*/
char	**unset_env_var(const char *name, char **envp)
{
	char	*var_name;
	char	**tmp;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!name || !envp)
		return (NULL);
	size = strlen_tab(envp);
	if (!ft_strncmp(name, "_=", 2))
		name = "$";
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		var_name = get_env_name(envp[i]);
		if (ft_strcmp(name, var_name) != 0)
			tmp[j++] = ft_strdup(envp[i]);
		(free(var_name), i++);
	}
	tmp[j] = 0;
	return (tmp);
}
