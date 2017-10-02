/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:41:21 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/01 20:41:22 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_valid_ne(t_filler *f, int i, int j)
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
			// ft_printf_fd(2, "%c", f->map[i + x][j + y]);
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
	// ft_printf_fd(2, "piece %d i %d j %d\n", piece, i, j);
	return (piece == 1 ? 1 : 0);
}

// static int	check_piece_ne(t_filler *f, int i, int j)
// {
// 	if (i + f->pzx < f->mx + f->pzx || j + f->pzy < f->my + f->pzy)
// 		return (0);
// 	else
// 		return (is_valid_ne(f, i, j));
// }

int	to_ne(t_filler *f)
{
	int	i;
	int	j;

	i = f->cx;
	while (i < f->mx)
	{
		j = f->cy;
		while (j < f->my)
		{
			if (is_valid_ne(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
