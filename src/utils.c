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

static int	is_valid(t_filler *f, int i, int j)
{
	int	x;
	int	y;
	int	piece;

	x = 0;
	piece = 0;
	while (x < f->pzx)
	{
		y = 0;
		while (y < f->pzy)
		{
			if (!f->map[x + i][y + j] && f->pz[x][y] == '*')
				return (0);
			else if (!f->map[x + i][y + j] && f->pz[x][y] == '.')
				continue ;
			else if ((f->map[x + i][y + j] == f->moi ||
			f->map[x + i][y + j] == f->moi + 32) && f->pz[x][y] == '*')
				piece += 1;
			else if ((f->map[x + i][y + j] == f->toi ||
			f->map[x + i][y + j] == f->toi + 32) && f->pz[x][y] == '*')
				return (0);
			y++;
		}
		x++;
	}
	return (piece);
}

int	check_piece(t_filler *f, int i, int j)
{
	if (i + f->pzx > f->mx)
		return (0);
	else if (j + f->pzy > f->my)
		return (0);
	else
		return (is_valid(f, i, j));
}

void	del_map(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->mx)
		ft_memdel((void**)&f->map[i++]);
	i = 0;
	while (i < f->pzx)
		ft_memdel((void**)&f->pz[i++]);
}
