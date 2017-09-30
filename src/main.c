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

static void	blank_map(t_filler *f)
{
	ft_arrdel((void**)f->map);
	ft_arrdel((void**)f->pz);
}

static void	create_map(t_filler *f)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	f->map = (char**)ft_memalloc(sizeof(char*) * f->my);
	f->map[i++] = ft_strdup(&line[4]);
	while (i < f->my)
	{
		get_next_line(0, &line);
		f->map[i++] = ft_strdup(&line[4]);
	}
	get_next_line(0, &line);
	i = ft_atoi(&line[6]);
	f->pz = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	j = 0;
	while (i > j)
	{
		get_next_line(0, &line);
		f->pz[j++] = ft_strdup(line);
	}
}

static void	set_players(t_filler *f)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	f->yo = line[10] == '1' ? 1 : 2;
	get_next_line(0, &line);
	f->my = ft_atoi(&line[8]);
	i = 8;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->mx = ft_atoi(&line[i]);
	get_init_coords(f);
}

int		main(int ac, char **av)
{
	int			i;
	char		*line;
	t_filler	f;

	(void)ac;
	(void)av;
	set_players(&f);
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		create_map(&f);
		if (i++ > 0)
			filler(&f);
		else
			put_first_piece(&f);
		// for (int i = 0; f.map[i]; i++)
		// 	ft_printf_fd(2, "[%s][%d]\n", f.map[i], i);
		// ft_printf_fd(2, "smn\n");
		blank_map(&f);
	}
	return (0);
}
