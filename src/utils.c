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

void	get_coords(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	// ft_printf_fd(2, "\n%d | %d\n", c, 'O');
	while (x < f->mx)
	{
		y = 0;
		while (y < f->my)
		{
			// ft_printf_fd(2, "\n%d %d\n", x, y);
			if (f->map[x][y] == f->moi)
			{
				ft_printf_fd(2, "%d %d %c\n", x, y, f->map[x][y]);
				f->cx = x;
				f->cy = y;
				return ;
			}
			// if (f->map[x][y] == f->toi)
			// {
			// 	f->opposx = x;
			// 	f->opposy = y;
			// }
			y++;
		}
		x++;
	}
	// f->where_to = f->opposx > f->cx ? 1 : 0;
}

void	del_map(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->mx)
		ft_bzero(f->map[i++], f->my);
	i = 0;
	while (i < f->pzx)
		ft_memdel((void**)&f->pz[i++]);
	// ft_memdel((void**)f->pz);
}
