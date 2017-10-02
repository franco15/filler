/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_se.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:41:27 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/01 20:41:28 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_valid_se(t_filler *f, int i, int j)
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

static int	check_piece_se(t_filler *f, int i, int j)
{
	if (i + f->pzx < f->mx + f->pzx || j + f->pzy < f->my + f->pzy)
		return (0);
	else
		return (is_valid_se(f, i, j));
}

int	to_se(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->mx)
	{
		j = 0;
		while (j < f->my)
		{
			if (check_piece_se(f, i, j))
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
