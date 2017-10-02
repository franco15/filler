/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:41:45 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/01 20:41:46 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_valid_nw(t_filler *f, int i, int j)
{
	int	x;
	int	y;
	int	piece;

	x = -1;
	piece = 0;
	while (++x < f->pzx)
	{
		y = -1;
		while (++y < f->pzy)
		{
			if (!f->map[x + i][y + j] && f->pz[x][y] == '.')
				continue ;
			if ((f->map[x + i][y + j] == f->moi ||
			f->map[x + i][y + j] == f->moi + 32) && f->pz[x][y] == '*')
				piece++;
			else if ((f->map[x + i][y + j] == f->toi ||
			f->map[x + i][y + j] == f->toi + 32) && f->pz[x][y] == '*')
				return (0);
		}
	}
	// ft_printf_fd(2, "piece %d\n", piece);
	return (piece == 1 ? 1 : 0);
}

static int	check_piece_nw(t_filler *f, int i, int j)
{
	if (i + f->pzx < 0 || j + f->pzy < 0)
		return (0);
	else
		return (is_valid_nw(f, i, j));
}

int	to_nw(t_filler *f)
{
	int	i;
	int	j;

	i = f->mx;
	while (i >= 0)
	{
		j = f->my;
		while (j >= 0)
		{
			if (check_piece_nw(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}
