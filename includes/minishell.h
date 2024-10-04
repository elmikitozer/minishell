/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:37:01 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/09 15:03:09 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "define.h"
# include "struct.h"

/* ************************************************************************** */
/*                               BUILT-INS                                    */
/* ************************************************************************** */

int		is_builtin(char *cmd);
int		cd_builtin(t_mini *mini, t_token token);
void	echo_builtin(char **args);
int		env_builtin(t_mini *mini, t_token token);
void	exit_builtin(t_mini *mini, t_token token);
int		export_builtin(t_mini *mini, t_token token);
void	exec_builtin(t_mini *mini, t_args *args, int i, int j);
int		redirection_builtin(t_mini *mini, t_token token, t_args *args);
int		pwd_builtin(t_mini *mini, t_token token);
int		unset_builtin(t_mini *mini, char **var_names);

// UTILS - cd
int		changepwd_env(t_mini *mini);
int		updatepath(t_mini *mini);
int		cd_and_update(t_mini *mini, const char *path);
int		expand_and_cd(t_mini *mini, const char *path);

/* ************************************************************************** */
/*                                SIGNAUX                                     */
/* ************************************************************************** */

void	ctrlc(int sig);
void	backslash(int sig);
void	signal_ctrlbshd(void);
void	ctrlcp(int sig);
void	signal_ctrl_c(void);
void	ctrlchd(int sig);
void	signal_ctrlbs(void);
void	signals(void);
void	backslash(int sig);
t_mini	*init_signals(void);

/* ************************************************************************** */
/*                                EXECUTION                                   */
/* ************************************************************************** */

// UTILS
void	initargs(t_mini *mini, t_args *args);
int		here_doc(t_mini *mini, t_args *args, char *delim, int i);
int		get_env(t_mini *mini, t_args *args);
void	waitprocess(t_args *args);
char	*pathcmd(char *path, char *cmd);
void	close_fdargs(t_args *args, int i);
void	tk_argsflags(t_args *args, int redir);

// REDIRECTIONS
int		redir_files(t_mini *mini, t_token token, t_args *args);
void	redirection_pipes(t_args *args, int index);

// HEREDOCS
void	exit_hd(int sig);
void	*newopenheredoc(t_mini *mini, char *delim);
int		new_count_heredocs(t_mini *mini);
char	**get_heredoc_delimiters(t_mini *mini, int nbheredocs);
void	exec_heredoc_in_child(t_mini *mini, char **delims, int nbheredocs);
void	*newheredoc(t_mini *mini);
void	free_hdocs(t_hdocs *hdocs);
void	init_hd(t_mini *mini, t_hdocs *hdocs, char *delim);

// EXECUTION
void	chose_exec(t_mini *mini, t_args *args, int i);
int		execution(t_args *args, t_mini *mini, int boolean, int i);
int		processes(t_mini *mini, t_args *args);
int		execmain(t_mini *mini);

/* ************************************************************************** */
/*                                EXPAND                                      */
/* ************************************************************************** */

// UTILS
char	*getvaluefromkey(char *key, char **env);
int		initinput(t_inputexpand *input, char *str, char **env, int lentotal);
int		check_quotes_exp(char *str);
void	reverse_quotes(char *str);
void	quotetype(t_inputexpand *input, int i);
int		dollarquote(t_inputexpand *input, int i, int *j, int lentotal);

// LEN
int		lenofkey(char *str);
int		inoutquotelen(char *str, int i, int *len);
int		expandlen(char *str, int i, int *len, char **env);
int		lentotal(char *str, char **env);

// EXPAND
int		expandexitcode(t_inputexpand *input, int i, int *j);
int		expanding(t_inputexpand *input, int i, int *j, int lentotal);
char	*newstring(int lentotal, char *str, char **env);
int		expand(t_mini *mini, char *str);
char	*expand_hd(t_mini *mini, char *str);

/* ************************************************************************** */
/*                                  INIT                                      */
/* ************************************************************************** */

// INIT
void	ft_freetab(char **tab);
void	init_data(t_mini *mini, char **env);
int		copy_env(t_mini *mini, char **env);

// PARSING
int		check_input(char *input);

/* ************************************************************************** */
/*                                PIPESPLITNG                                 */
/* ************************************************************************** */

// UTILS
int		check_quotes(char *str);
void	inchev(const char *s, size_t *words, bool *inword, int *i);
void	isinword(bool *inword, size_t *words);
int		splitpipe(t_mini *mini);

// SPLITSEP
size_t	count_wordssplitsep(char const *s, char c, char *sep);
void	fill_tab(char *new, char const *s, char c, char *sep);
size_t	findcount(const char *s, size_t index, char c, char *sep);
int		set_mem(char **tab, char const *s, char c, char *sep);
char	**ft_splitseparator(char const *s, char c, char *sep);

/* ************************************************************************** */
/*                                REDIR                                       */
/* ************************************************************************** */

// UTILS
void	tokensize(char **tab, t_token *tk);
int		isaredirection(char *str);
void	init_token(t_token *tk);

// REDIR
void	token(char **tab, t_token *tk);
char	*remove_quote(char *str);
t_token	redir(char *input);
int		table_token_redir(t_mini *mini);

/* ************************************************************************** */
/*                                UTILS                                       */
/* ************************************************************************** */

// Builtins utils
char	*find_env_var(char **env, const char *name);
char	*get_env_value(char *arg);
char	*get_env_name(char *arg);
char	**set_env_var(char *name, char *value, char **envp);
char	**unset_env_var(const char *name, char **envp);

// Arrays
int		strlen_tab(char **array);
void	free_array(char **array);

// Errors
int		error_msg(char *exe, char *err_msg, int exit_code);
void	error_exit(t_mini *mini, char *exe, char *err_msg, int exit_code);

// Exit && Free minishell
int		exit_minishell(t_mini *mini);
void	free_minishell(t_mini *mini, int fenv);

#endif
