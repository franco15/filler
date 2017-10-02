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
			if (f->map[x][y] == f->moi)
			{
				f->cx = x;
				f->cy = y;
				ft_printf_fd(2, "\n%d %d\n", x, y);
				return ;
			}
			y++;
		}
		x++;
	}
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
	ft_memdel((void**)f->pz);
}
