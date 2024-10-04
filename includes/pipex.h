/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:45:48 by myevou            #+#    #+#             */
/*   Updated: 2024/08/25 17:52:45 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_args
{
	char	*in;
	char	*out;
	int		nbcmds;
	int		old_pipes;
	int		fd[2];
	int		heredoc;
	int		heredocfd;
	int		flag;
	char	**cmds;
	char	**env;
	char	**envp;
	pid_t	*pid;
}			t_args;

// UTILS
void		ft_freetab(char **array);
void		waitprocess(t_args *args);
void		here_doc(t_args *args, char *delim);
void		initargs(t_args *args, char **av, char **env, int ac);
void		ft_error_exit(char *s, t_args *args, int last);

// ENV
void		get_env(t_args *args, char **envpm);
char		*pathcmd(char *path, char *cmd);
void		chose_exec(t_args *args, int i);

// MAIN
void		*exec(t_args *args, int boole, int i);

// SPLIT
char		**ft_split(char const *s, char c);

#endif
