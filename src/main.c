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

static void	fill_map(t_filler *f)
{
	int		i;
	char	*line;

	i = 0;
	// ft_printf_fd(2, "\n%d | %d\n", f->mx, f->my);
	while (i < f->mx)
	{
		get_next_line(0, &line);
		ft_strcpy(f->map[i++], &line[4]);
	}
	get_next_line(0, &line);
	f->pzx = ft_atoi(&line[6]);
	i = 6;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->pzy = ft_atoi(&line[i]);
	i = 0;
	while (i < f->pzx)
	{
		f->pz[i] = (char*)ft_memalloc(sizeof(char) * f->my);
		get_next_line(0, &line);
		ft_strcpy(f->pz[i++], line);
	}
	// f->rx = 0;
	// f->ry = 0;
}

static void	create_map(t_filler *f)
{
	int		i;

	i = 0;
	f->map = (char**)ft_memalloc(sizeof(char*) * f->mx);
	f->pz = (char**)ft_memalloc(sizeof(char*) * f->mx);
	while (i < f->mx)
		f->map[i++] = (char*)ft_memalloc(sizeof(char) * f->my);
	f->cx = 0;
	f->cy = 0;
	f->ded = 0;
	f->rx = 0;
	f->ry = 0;
}

static void	set_players(t_filler *f)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	f->moi = line[10] == '1' ? 'O' : 'X';
	f->toi = f->moi == 'O' ? 'X' : 'O';
	get_next_line(0, &line);
	f->mx = ft_atoi(&line[8]);
	i = 8;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->my = ft_atoi(&line[i]);
	f->where_to = f->moi == 'O' ? 0 : 1;
}

int		main(int ac, char **av)
{
	// int			i;
	char		*line;
	t_filler	f;

	(void)ac;
	(void)av;
	// i = 0;
	set_players(&f);
	create_map(&f);
	while (get_next_line(0, &line) > 0)
	{
		// ft_printf_fd(2, "\nb4 create_map\n");
		fill_map(&f);
		// ft_printf_fd(2, "\n\n\n");
		// for (i = 0; i < f.mx; i++)
		// 	ft_printf_fd(2, "%s\n", f.map[i]);
		// ft_printf_fd(2, "\nb4 filler()\n");
		filler(&f);
		// ft_printf_fd(2, "smn\n");
		// ft_printf_fd(2, "\nb4 del_map\n");
		del_map(&f);
		// ft_printf_fd(2, "\nend turn\n");
	}
	ft_memdel((void**)f.map);
	ft_memdel((void**)f.pz);
	return (0);
}
