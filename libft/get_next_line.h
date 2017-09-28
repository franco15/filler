/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 03:24:17 by coco              #+#    #+#             */
/*   Updated: 2017/06/29 03:24:18 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "minilibft.h"

# define BUFF_SIZE 1024

typedef struct		s_line
{
	char			*rem;
	char			*ln;
	size_t			size;
	int				w;
}					t_line;

typedef struct		s_file
{
	t_line			*content;
	int				fd;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
