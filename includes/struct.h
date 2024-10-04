/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:45:42 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/08 14:17:34 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

extern int				g_sig;

typedef struct s_env
{
	char				*name;
	char				*value;
	int					equal_sign;
	struct s_env		*next;
}						t_env;

typedef struct hdocs
{
	char				*delim;
	char				*content;
	char				*filename;
	int					fd;
}						t_hdocs;

typedef struct s_inputexpand
{
	int					len;
	int					lenkey;
	int					quotetype;
	char				*new;
	char				*str;
	char				**env;

}						t_inputexpand;

typedef struct s_commands
{
	int					argc;
	char				**args;
	char				*str;
	struct s_commands	*next;
}						t_commands;

typedef struct s_token
{
	int					*redir;
	char				**filename;
	char				**args;
	char				*cmd;
	char				**delim;
	int					args_count;
	int					redir_count;
	int					fail;
}						t_token;

typedef struct s_args
{
	int					nbcmds;
	int					old_pipes;
	int					fd[2];
	int					flag;
	char				**env;
	char				**envp;
	pid_t				*pid;
}						t_args;

typedef struct s_mini
{
	char				**env_tab;
	char				**envpath;
	char				**cmd_path;
	char				**inputpipesplited;
	int					pipe_nb;
	char				*input;
	int					*redir;
	char				*cmd;
	int					fail;
	int					here_doc;
	char				**delim;
	t_hdocs				*hdocs;
	t_env				*env;
	t_token				*token;
	t_commands			*cmd_str;
}						t_mini;

#endif
