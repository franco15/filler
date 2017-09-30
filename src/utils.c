/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:41:25 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 21:41:26 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_coords(t_filler *f, char c)
{
	int	x;
	int	y;

	y = 0;
	while (f->map[y])
	{
		x = 0;
		while (f->map[y][x])
		{
			if (f->map[y][x] == c)
			{
				f->px = x;
				f->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_init_coords(t_filler *f)
{
	if (f->mx == 17)
	{
		f->px = f->yo == 1 ? 2 : 15;
		f->py = f->yo == 1 ? 8 : 13;
	}
	else if (f->mx == 40)
	{
		f->px = f->yo == 1 ? 4 : 33;
		f->py = f->yo == 1 ? 4 : 20;
	}
	else if (f->mx == 99)
	{
		f->px = f->yo == 1 ? 31 : 71;
		f->py = f->yo == 1 ? 30 : 70;
	}
}

void	put_first_piece(t_filler *f)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	if (f->pz[y + 1][x] == '*')
	{
		ft_printf_fd(1, "%d, %d\n", f->py, f->px);
		return ;
	}
	while (f->pz[++y])
	{
		x = -1;
		while (f->pz[y][++x])
		{
			if (is_valid(f))
			{
				ft_printf_fd(1, "%d, %d\n", f->py, f->px);
				return ;
			}
		}
	}
}
