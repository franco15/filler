/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:54:11 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/19 17:54:14 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static t_file	*newelem(int fd)
{
	t_file	*elem;

	if (!(elem = ft_memalloc(sizeof(t_file))))
		return (0);
	elem->content = ft_memalloc(sizeof(t_line));
	elem->fd = fd;
	return (elem);
}

static void		return_line(t_line *tmp, char *buff, char **line, long l)
{
	size_t	i;
	char	*rd;

	if ((rd = ft_strchr(buff, '\n')) || (!*buff && tmp->ln))
	{
		if (rd && rd + 1)
			tmp->rem = ft_strdup(rd + 1);
		tmp->w = 1;
	}
	else if (!l && !tmp->ln && !*buff)
		tmp->w = 0;
	i = ft_strlenc(buff, '\n');
	tmp->ln = ft_realloc(tmp->ln, tmp->size, tmp->size + i + 1);
	tmp->ln = ft_strncat(tmp->ln, buff, i);
	tmp->size = ft_strlen(tmp->ln);
	*line = tmp->ln;
}

static int		read_line(t_file *l, char **line)
{
	char	*buff;
	t_line	*tmp;
	long	i;

	buff = ft_strnew(BUFF_SIZE);
	tmp = l->content;
	tmp->ln = 0;
	tmp->w = -1;
	i = 0;
	while (tmp->w < 0)
	{
		if (tmp->rem && *tmp->rem)
		{
			if (*tmp->rem)
				buff = ft_strcat(buff, tmp->rem);
			ft_strdel(&tmp->rem);
			tmp->rem = 0;
		}
		else if ((i = read(l->fd, buff, BUFF_SIZE)) < 0)
			return (tmp->w);
		return_line(tmp, buff, line, i);
		ft_bzero(buff, BUFF_SIZE);
	}
	ft_memdel((void**)&buff);
	return (tmp->w);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*node;
	t_file			*file;
	char			buff[BUFF_SIZE];

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!list)
		list = ft_lstnew(newelem(fd), sizeof(t_list));
	node = list;
	while (node)
	{
		file = node->content;
		if (file->fd == fd)
			return (read_line(file, line));
		node = node->next;
	}
	node = ft_lstnew(newelem(fd), sizeof(t_list));
	ft_lstaddback(&list, node);
	return (read_line(node->content, line));
}
