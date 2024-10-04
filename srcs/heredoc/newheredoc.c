/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newheredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:59:13 by myevou            #+#    #+#             */
/*   Updated: 2024/09/09 15:03:22 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_hdocs(t_hdocs *hdocs)
{
	if (hdocs)
	{
		(free(hdocs->filename), hdocs->filename = NULL);
	}
}

void	*newopenheredoc(t_mini *mini, char *delim)
{
	t_hdocs	hdocs;

	init_hd(mini, &hdocs, delim);
	hdocs.fd = open(hdocs.filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	mini->hdocs = &hdocs;
	while (1)
	{
		hdocs.content = readline("> ");
		if (!hdocs.content)
		{
			ft_printf(CTRLD_HD, hdocs.delim);
			free(hdocs.content);
			break ;
		}
		if (!ft_strcmp(hdocs.content, hdocs.delim))
		{
			free(hdocs.content);
			break ;
		}
		hdocs.content = expand_hd(mini, hdocs.content);
		(ft_putendl_fd(hdocs.content, hdocs.fd), free(hdocs.content));
	}
	return (free(hdocs.filename), close(hdocs.fd), NULL);
}

void	*newheredoc(t_mini *mini)
{
	int		nbheredocs;
	int		pid;
	int		error;

	nbheredocs = new_count_heredocs(mini);
	mini->here_doc = nbheredocs;
	mini->delim = get_heredoc_delimiters(mini, nbheredocs);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	error = 0;
	if (pid == -1)
		return (NULL);
	if (pid == 0)
		exec_heredoc_in_child(mini, mini->delim, nbheredocs);
	signal(SIGINT, &ctrlc);
	waitpid(pid, &error, 0);
	if (WIFEXITED(error))
		g_sig = WEXITSTATUS(error);
	if (WIFSIGNALED(error))
		g_sig = 128 + WTERMSIG(error);
	free_array(mini->delim);
	return (NULL);
}
