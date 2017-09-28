/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:38:14 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 10:38:15 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <errno.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

/*
** conv.c
*/
char	*ft_itoa_base(long long int n, int b);

/*
** fd.c
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putcharn_fd(int c, int n, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
** ft_printf.c
*/
void	ft_printfcolor_fd(int fd, const char *format, ...);
void	ft_printf_fd(int fd, const char *format, ...);

/*
** get_next_line.c
*/
int		get_next_line(const int fd, char **line);

/*
** lst.c
*/
t_list	*ft_lstnew(void const *content, size_t size);
void	ft_lstaddback(t_list **alst, t_list *new);

/*
** mem.c
*/
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_memdel(void **ap);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** mem2.c
*/
void	*ft_realloc(void *ptr, size_t size, size_t newsize);

/*
** strings.c
*/
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_strdel(char **as);
char	*ft_strchr(const char *s, int c);

/*
** strings2.c
*/
size_t	ft_strlenc(const char *s, char c);
char	*ft_strcpy(char *dst, const	char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);

#endif
