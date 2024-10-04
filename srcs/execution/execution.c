/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:54:18 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 11:56:37 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fail_execve(t_mini *mini, char *cmd)
{
	struct stat	path_stat;

	if (!stat(cmd, &path_stat) && !ft_strncmp(cmd, "/", 1))
		error_exit(mini, cmd, "Is a directory", 126);
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2))
	{
		if (S_ISDIR(path_stat.st_mode))
			error_exit(mini, cmd, "Is a directory", 126);
		if (!stat(cmd, &path_stat))
			error_exit(mini, cmd, "Permission denied", 126);
		error_exit(mini, cmd, "No such file or directory", 127);
	}
	if (ft_strchr(cmd, '/'))
		error_exit(mini, cmd, "No such file or directory", 127);
	error_exit(mini, cmd, "command not found", 127);
}

void	chose_exec(t_mini *mini, t_args *args, int i)
{
	int	j;

	if (mini->token[i].cmd)
	{
		j = is_builtin(mini->token[i].cmd);
		if (j)
			return (exec_builtin(mini, args, i, j));
		if (ft_strchr(mini->token[i].cmd, '/') && ft_strncmp(mini->token[i].cmd,
				"./", 2))
			execution(args, mini, 0, i);
		else
			execution(args, mini, 1, i);
	}
	ft_freetab(args->env);
	free_minishell(mini, 0);
	exit(g_sig);
}

int	execution(t_args *args, t_mini *mini, int boolean, int i)
{
	char	**cmd;
	char	*tmp;

	cmd = mini->token[i].args;
	if (boolean && mini->envpath)
	{
		while (mini->envpath[++i])
		{
			if (cmd[0][0] == 0)
				return (ft_putstr_fd("minishell: command not found\n", 2), 1);
			tmp = pathcmd(mini->envpath[i], cmd[0]);
			if (access(tmp, F_OK | X_OK) == 0)
			{
				if (execve(tmp, cmd, mini->env_tab) == -1)
					return (fail_execve(mini, cmd[0]), free(tmp), 1);
			}
			free(tmp);
		}
		if (execve(cmd[0], cmd, mini->env_tab) == -1)
			fail_execve(mini, cmd[0]);
		return (1);
	}
	else if (execve(cmd[0], cmd, args->envp))
		return (fail_execve(mini, cmd[0]), 1);
	return (ft_freetab(cmd), 0);
}

int	processes(t_mini *mini, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbcmds)
	{
		(signal(SIGINT, &ctrlcp), signal(SIGQUIT, &backslash), pipe(args->fd));
		if (!args->pid)
			return (free_minishell(mini, 0), 0);
		args->pid[i] = fork();
		if (args->pid[i] == 0)
		{
			(free(args->pid), args->pid = NULL, redirection_pipes(args, i));
			if (mini->token[i].redir && redir_files(mini, mini->token[i], args))
				return (free_minishell(mini, 1), 1);
			(chose_exec(mini, args, i), free_minishell(mini, 1));
		}
		else
			close_fdargs(args, i);
	}
	return (close(args->fd[0]), 0);
}

int	execmain(t_mini *mini)
{
	static t_args	args = {0};

	initargs(mini, &args);
	if ((mini->pipe_nb == 1) && (is_builtin(mini->token[0].cmd)))
	{
		if (mini->token[0].redir)
			redirection_builtin(mini, mini->token[0], &args);
		else
			free_minishell(mini, 0);
		return (0);
	}
	if (get_env(mini, &args))
		return (1);
	args.pid = malloc(sizeof(pid_t) * args.nbcmds);
	if (!args.pid)
		exit(2);
	mini->fail = processes(mini, &args);
	if (!mini->fail)
		waitprocess(&args);
	if (((g_sig == 2) && ((!ft_strncmp(mini->token[0].cmd, "echo", 4))
				|| (!ft_strncmp(mini->token[0].cmd, "cat", 3)))))
		g_sig = 0;
	free_minishell(mini, 0);
	free(args.pid);
	return (0);
}
