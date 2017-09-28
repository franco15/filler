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

static void	create_map(t_filler *f)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	f->map = (char**)ft_memalloc(sizeof(char*) * f->my);
	while (i < f->my)
	{
		get_next_line(0, &line);
		f->map[i++] = ft_strdup(&line[4]);
	}
	get_next_line(0, &line);
	i = ft_atoi(&line[6]);
	ft_printf_fd(2, "[%d]\n", i);
	f->pz = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	j = 0;
	while (i > j)
	{
		get_next_line(0, &line);
		f->pz[j++] = ft_strdup(line);
	}
	// for (i = 0; f->pz[i]; i++)
		// ft_printf_fd(2, "[%s]\n", f->pz[i]);
}

static void	set_players(t_filler *f)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	f->yo = line[10] == '1' ? 1 : 2;
	f->tu = line[10] == '1' ? 2 : 1;
	get_next_line(0, &line);
	f->my = ft_atoi(&line[8]);
	i = 8;
	while (ft_isdigit(line[i]))
		i++;
	i++;
	f->mx = ft_atoi(&line[i]);
	// ft_printf_fd(2, "\n[%d    %d]\n", f->mx, f->my);
}

int		main(int ac, char **av)
{
	t_filler	f;

	(void)ac;
	(void)av;
	set_players(&f);
	create_map(&f);
	return (0);
}
