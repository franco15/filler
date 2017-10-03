/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:41:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 10:41:04 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_pz(t_filler *f)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	f->pzx = ft_atoi(&line[6]);
	i = 6;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->pzy = ft_atoi(&line[i]);
	i = 0;
	if (!f->pz)
		f->pz = (char**)ft_memalloc(sizeof(char*) * f->pzx);
	while (i < f->pzx)
	{
		get_next_line(0, &line);
		f->pz[i++] = ft_strdup(line);
	}
}

static void	create_map(t_filler *f)
{
	int		i;
	char	*line;

	i = 0;
	if (!f->map)
		f->map = (char**)ft_memalloc(sizeof(char*) * f->mx);
	get_next_line(0, &line);
	while (i < f->mx)
	{
		// if is digito?
		get_next_line(0, &line);
		f->map[i++] = ft_strdup(&line[4]);
	}
	get_pz(f);
	f->rx = 0;
	f->ry = 0;
	f->ded = 0;
}

static void	map_coords(t_filler *f, char *line)
{
	int		i;

	i = 8;
	f->mx = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->my = ft_atoi(&line[i]);
}

int		main(void)
{
	char		*line;
	t_filler	*f;

	if (!(f = (t_filler*)ft_memalloc(sizeof(t_filler))))
		return (-1);
	get_next_line(0, &line);
	f->moi = line[10] == '1' ? 'O' : 'X';
	f->toi = f->moi == 'O' ? 'X' : 'O';
	f->where_to = f->moi == 'O' ? 0 : 1;
	while (1)
	{
		get_next_line(0, &line);
		map_coords(f, line);
		create_map(f);
		filler(f);
		del_map(f);
		if (f->ded == 1)
			break ;
	}
	// ft_memdel((void**)f->map);
	// ft_memdel((void**)f->pz);
	// ft_memdel((void**)&f);
	return (0);
}
