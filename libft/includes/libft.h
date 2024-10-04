/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:35 by gchenot           #+#    #+#             */
/*   Updated: 2023/11/06 15:03:35 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//Libft libs
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

//GNL libs
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

//Printf lib
# include <stdarg.h>

/*libc functions*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *b, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memdealloc(void *ptr);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
// void	*ft_realloc(void *ptr, size_t new_size);
void	*ft_realloc(void *ptr, size_t current_size, size_t new_size);
// char	*ft_strdup(const char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*bonus functions*/
typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*GNL*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// char	*ft_read_line(char *str);
// char	*ft_update_start(char *str);
// char	*get_next_line(int fd, int state);
// size_t	ft_strlen_gnl(char *str);
// char	*ft_strchr_gnl(char *s, int c);
// char	*ft_strcat(char *dest, char *s1, char *s2);
// char	*ft_strjoin_gnl(char *start, char *buff);

t_list	*ft_lstlast(t_list *stash);
void	extract_line(t_list *stash, char **line);
size_t	ft_strlen(const char *str);
int		found_line(t_list *stash);
void	generate_line(t_list *stash, char **line);
void	add_to_stash(t_list **stash, char *buff, int read_count);
void	read_and_stash(int fd, t_list **stash);
void	clean_stash(t_list **stash);
void	free_stash(t_list *stash);
char	*get_next_line(int fd, int state);

/*PRINTF*/
char	*ft_itoa(int n);
size_t	ft_hex_len(unsigned int nbr);
void	ft_put_hex_format(unsigned int nbr, char format);
size_t	ft_put_hex(unsigned int nbr, char format);
size_t	ft_put_percent(void);
size_t	ft_uintptr_len(unsigned long long nbr);
void	ft_put_uintptr_hex(unsigned long long nbr);
size_t	ft_put_uintptr(unsigned long long ptr);
size_t	ft_put_unsigned(unsigned int n);
size_t	ft_printf_putchar_fd(char c, int fd);
size_t	ft_nbr_len(unsigned int nbr);
size_t	ft_printf_putnbr_fd(int nb, int fd);
size_t	ft_printf_putstr_fd(char *str, int fd);
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *str, ...);

#endif
