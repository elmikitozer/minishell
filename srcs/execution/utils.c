/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:50:09 by myevou            #+#    #+#             */
/*   Updated: 2024/09/08 11:57:47 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	here_docpre(t_mini *mini, t_args *args, int i)
{
	char	*tmp;
	char	*filename;
	int		fd;

	tmp = ft_itoa(mini->here_doc);
	filename = ft_strjoin(tmp, ".tmp");
	mini->here_doc++;
	args->flag = O_APPEND;
	fd = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0666);
	free(mini->token->filename[i]);
	mini->token->filename[i] = ft_strdup(filename);
	(free(filename), filename = NULL);
	(free(tmp), tmp = NULL);
	return (fd);
}

int	here_doc(t_mini *mini, t_args *args, char *delim, int i)
{
	int		fd;
	char	*str;

	fd = here_docpre(mini, args, i);
	if (fd == -1)
		return (0);
	(signal_ctrlbshd(), signal(SIGINT, &ctrlchd), g_sig = 0);
	while (1)
	{
		str = readline("> ");
		if (!str)
		{
			if (g_sig == EXEC_CTRL_C)
				return (close(fd), free(delim), free_minishell(mini, 1),
					exit(g_sig), 0);
			ft_printf("minishell: warning: here-document delimited by"
				"end-of-file (wanted `%s')\n", delim);
			return (close(fd), 1);
		}
		if (!ft_strcmp(delim, str))
			return (close(fd), 1);
		str = expand_hd(mini, str);
		(ft_putstr_fd(str, fd), ft_putstr_fd("\n", fd), free(str));
	}
	return (close(fd), 0);
}

int	get_env(t_mini *mini, t_args *args)
{
	int	i;

	i = -1;
	while (mini->env_tab[++i])
	{
		if (!ft_strncmp(mini->env_tab[i], "PATH=", 5))
		{
			mini->envpath = ft_split(mini->env_tab[i], ':');
			if (!args->env)
			{
				ft_freetab(args->env);
				free(args);
				return (1);
			}
		}
	}
	return (0);
}

void	waitprocess(t_args *args)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < args->nbcmds)
	{
		if (!args->pid)
			exit(2);
		waitpid(args->pid[i++], &err, 0);
		if (WIFEXITED(err))
			g_sig = WEXITSTATUS(err);
		if (WIFSIGNALED(err))
			g_sig = 128 + WTERMSIG(err);
		if (g_sig == 131)
			(ft_putstr_fd("Quit: (core dumped)\n", 2), g_sig = 131);
		signal(SIGINT, &ctrlc);
		signal(SIGQUIT, SIG_IGN);
	}
}

char	*pathcmd(char *path, char *cmd)
{
	char	*var;
	size_t	i;
	size_t	count;

	var = ft_calloc(ft_strlen(path) + ft_strlen(cmd) + 2, 1);
	if (!var)
		return (NULL);
	i = -1;
	while (path[++i])
		var[i] = path[i];
	var[i++] = '/';
	count = -1;
	while (cmd[++count])
		var[i + count] = cmd[count];
	var[i + count] = 0;
	return (var);
}
