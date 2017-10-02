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

	i = 0;
	// ft_printf_fd(2, "\n%d | %d\n", f->mx, f->my);
	get_next_line(0, &line);
	i = ft_strlen(line);
	// ft_printf_fd(2, "[%s] | %c | %c\n", line, line[6], line[8]);
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
	// ft_printf_fd(2, "\n%d | %d\n", f->pzx, f->pzy);
}

static void	create_map(t_filler *f)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	if (!f->map)
		f->map = (char**)ft_memalloc(sizeof(char*) * f->mx);
	while (i < f->mx)
	{
		get_next_line(0, &line);
		f->map[i++] = ft_strdup(&line[4]);
	}
	get_pz(f);
	f->rx = 0;
	f->ry = 0;
	f->ded = 0;
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
	int			i;
	// char		*line;
	t_filler	f;

	(void)ac;
	(void)av;
	i = 0;
	set_players(&f);
	// create_map(&f);
	while (1)
	{
		// ft_printf_fd(2, "\nb4 create_map\n");
		create_map(&f);
		sleep(1);
		// ft_printf_fd(2, "\n\n\n");
		// for (i = 0; i < f.pzx; i++)
			// ft_printf_fd(2, "%s\n", f.pz[i]);
		// ft_printf_fd(2, "\nb4 filler()\n");
		filler(&f);
		if (f.ded == 1)
			break ;
		// ft_printf_fd(2, "smn\n");
		// ft_printf_fd(2, "\nb4 del_map\n");
		// del_map(&f);
		// ft_printf_fd(2, "\nend turn\n");
	}
	ft_memdel((void**)f.map);
	// ft_memdel((void**)f.pz);
	return (0);
}
