/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:14:13 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/23 14:18:36 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "struct.h"
# define BUF_SIZE	1
# define RESET		"\e[0m"
# define BLUE		"\e[0;34m"
# define RED		"\e[0;31m"
# define YELLOW		"\e[0;33m"
# define GREEN		"\e[0;32m"
# define BACKRED	"\e[41m"
# define WHITE		"\e[4;37m"

/*
**	Recast of list functions
*/

t_head	*ft_lst_init_head(t_head *head, t_lst *elem);
t_lst	*ft_lst_create_no_malloc(void *data);
t_lst	*ft_lst_match(t_head *head, void *data, int (*cmp)(void *, void *));
t_lst	*ft_lst_pop(t_head *head, size_t pos);
int		ft_lst_foreach(t_head *head, int (*func)(void *));
int		ft_lst_push_front(t_head *head, t_lst *elem);
int		ft_lst_push_back(t_head **head, t_lst *elem);
int		ft_lst_del_one(t_head *head, int (*cmp)(void *, void *), void *data);
void	ft_lst_del_match(t_head *head, void *data, int (*cmp)(void *, void *),
												void (*del)(void *));
void	ft_lst_del(t_head *head);

int		ft_lst_first_match(t_head *head, void (*cmp)(void), void *data);
void	ft_lst_print_elem(t_head *head, void (*print_data), void *data);
void	ft_lst_print(t_head *head, void (*print_data));

int		ft_atoi(char *str);
int		get_next_line(int const fd, char **line);
void	ft_bzero(void *s, size_t n);
t_list	*ft_create_elem(char *data);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
char	*ft_itoa(int n);
t_list	*ft_list_push_back(t_list *list, t_list *new);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar(char c);
int		ft_putchar_fd(char c, int fd);
void	ft_putchar_l(char c);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putlist(t_list *list);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
void	ft_strcolor(char *color, char *str);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strisdigit(char *str);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *c);
char	*ft_strndup(const char *s1, int count);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
void	ft_swap(int a, int b);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
