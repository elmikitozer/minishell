/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:06:40 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 16:42:34 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "../libft/includes/libft.h"

# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <bits/sigaction.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/types.h>

# define SUCCESS 0
# define ERROR 1

# define EXEC_CTRL_D 0
# define EXEC_CTRL_C 130
# define EXEC_CTRL_BS 131
# define ERROR_CMD_EXEC 				126
# define ERROR_CMD_NOT_FOUND 			127
# define ERROR_SYNTAX 					258
# define ER_TK 		"minishell: syntax error near unexpected token `newline'\n"
# define ERR_CHDIR		"chdir: error retrieving current directory : \
							getcwd: cannot access parent directories: \
							No such file or directory\n"
# define CTRLD_HD		"minishell: warning: here-document delimited by \
end-of-file (wanted `%s')\n"
# define ERR_EX		"minishell: export: `%s': not a valid identifier\n"
# define RESET	"\1\033[0m\2"
# define BLUE	"\1\033[1;34m\2"

#endif
