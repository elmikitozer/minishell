/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execredir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:52:59 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 14:01:15 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	normredirbuiltin(t_mini *mini, t_token token, t_args *args)
{
	int		fd;
	int		i;
	char	*tmp;

	i = -1;
	(void)mini;
	while (++i < token.redir_count)
	{
		tmp = ft_strjoin(token.filename[i], "\n");
		tk_argsflags(args, token.redir[i]);
		if (token.redir[i] == -2)
		{
			fd = open(tmp, O_RDONLY);
			free(tmp);
		}
		if (token.redir[i] == -1)
			fd = open(token.filename[i], O_RDONLY);
		else if (token.redir[i] > 0)
			fd = open(token.filename[i], O_RDWR | args->flag | O_CREAT, 0666);
		if (fd < 0)
			return (free(tmp), error_msg(token.filename[i],
					"No such file or directory", 1));
		(dup2(fd, token.redir[i] > 0), free(tmp));
	}
	return (0);
}

int	redirection_builtin(t_mini *mini, t_token token, t_args *args)
{
	int	saved_stdin;
	int	saved_stdout;
	int	saved_stderr;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	saved_stderr = dup(STDERR_FILENO);
	if (!normredirbuiltin(mini, token, args))
		exec_builtin(mini, args, 0, is_builtin(token.cmd));
	(dup2(saved_stdin, STDIN_FILENO), dup2(saved_stdout, STDOUT_FILENO),
		dup2(saved_stderr, STDERR_FILENO));
	(close(saved_stdin), close(saved_stdout), close(saved_stderr));
	return (0);
}

static void	fd_error(t_mini *mini, t_token *token, int i, char *tmp)
{
	if (access(tmp, F_OK) == -1)
	{
		(free(tmp), tmp = NULL);
		error_exit(mini, token->filename[i], "No such file or directory", 1);
	}
	(free(tmp), tmp = NULL);
	error_exit(mini, token->filename[i], "Permission denied", 1);
}

int	redir_files(t_mini *mini, t_token token, t_args *args)
{
	int		fd;
	int		i;
	char	*tmp;

	i = -1;
	while (++i < token.redir_count)
	{
		tmp = ft_strjoin("tmp", token.filename[i]);
		if (token.redir[i] == 2)
			args->flag = O_APPEND;
		else
			args->flag = O_TRUNC;
		if (token.redir[i] == -2)
			fd = open(tmp, O_RDONLY);
		if (token.redir[i] == -1)
			fd = open(token.filename[i], O_RDONLY);
		else if (token.redir[i] > 0)
			fd = open(token.filename[i], O_RDWR | args->flag | O_CREAT, 0666);
		if (fd < 0)
			fd_error(mini, &token, i, tmp);
		dup2(fd, token.redir[i] > 0);
		free(tmp);
	}
	return (0);
}

void	redirection_pipes(t_args *args, int index)
{
	if (index != args->nbcmds - 1)
		dup2(args->fd[1], STDOUT_FILENO);
	if (index != 0)
	{
		dup2(args->old_pipes, STDIN_FILENO);
		close(args->old_pipes);
	}
	close(args->fd[0]);
	close(args->fd[1]);
}
