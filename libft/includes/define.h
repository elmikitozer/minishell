/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:13:50 by myevou            #+#    #+#             */
/*   Updated: 2024/08/25 17:49:12 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../libft/includes/libft.h"
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1

// Errors
# define ERR_DUP "Error->Failed to duplicate file descriptor\n"
# define ERR_ENV_HOME "Error->HOME not found in env\n"
# define ERR_GNL "Error->Wrong return from GNL\n"
# define ERR_MALLOC "Error->Malloc failed\n"
# define ERR_OPEN_FILE "Error->Failed to open file\n"
# define ERR_PROHIBIDED_CHAR "prohibited character"
# define ERR_PWD_NOT_SET "Environment variable PWD not set"
# define ERR_SYNTAX "syntax error near unexpected token"
# define ERR_TERM "Error->Failed to get terminal type\n"
# define ERR_UNCLOSE_CHAR "unclosed character"

#endif
