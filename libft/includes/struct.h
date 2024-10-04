/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:58:14 by myevou            #+#    #+#             */
/*   Updated: 2024/08/25 17:47:53 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*name;
	struct s_env	*next;

}					t_env;

typedef struct s_prompt
{
	char			*prompt;
}					t_prompt;

typedef struct s_mini
{
	t_env			*env;
	char			**env_tab;
	t_prompt		*prompt;
}					t_mini;

typedef struct s_minishell
{
	char			**cmds;
}					t_minishell;

#endif
