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
			// if (f->map[i + x][j + y])
			// 	ft_printf_fd(2, "%c | %d | %d\n", f->map[i + x][j + y], x + i, y + j);
			// if (!f->map[x + i][y + j] && f->pz[x][y] == '.')
			// 	continue ;
			// ft_printf_fd(2, "%c | %c\n", f->map[x + i][y + j], f->pz[x][y]);
			if (f->map[x + i][y + j] && (f->map[x + i][y + j] == f->moi ||
			f->map[x + i][y + j] == f->moi + 32) && f->pz[x][y] == '*')
				piece += 1;
			else if (f->map[x + i][y + j] && (f->map[x + i][y + j] == f->toi ||
			f->map[x + i][y + j] == f->toi + 32) && f->pz[x][y] == '*')
				return (0);
			y++;
		}
		x++;
	}
	// ft_printf_fd(2, "piece %d | i %d | j %d\n", piece, i, j);
	return (piece);
}

int	check_piece(t_filler *f, int i, int j)
{
	ft_printf_fd(2, "check_piece %d | %d | %d | %d | %d | %d\n", i, j, f->mx, f->my, f->pzx, f->pzy);
	if (i + f->pzx> f->mx)
	{
		ft_printf_fd(2, "puta\n");
		return (0);
	}
	else if (j + f->pzx > f->my)
	{
		ft_printf_fd(2, "madre\n");
		return (0);
	}
	else
	{
		printf("alv\n");
		return (is_valid(f, i, j));
	}
	ft_printf_fd(2, "ded:c\n");
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
	ft_memdel((void**)f->pz);
}
