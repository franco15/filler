/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:46:30 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 19:46:31 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** map00 p1 [2, 9] p2 [15, 13]
** map01 p1 [4, 4] p2 [33, 20]
** map02 p1 [31, 30] p2 [71, 70]
*/

// int		is_valid(t_filler *f)
// {
// 	(void)f;
// 	return (0);
// }

static int	where_to_question_mark(t_filler *f)
{
	if (f->where_to == 0)
		return (to_nw(f));
	else if (f->where_to == 1)
		return (to_ne(f));
	else if (f->where_to == 2)
		return (to_sw(f));
	else if (f->where_to == 3)
		return (to_se(f));
}

void	filler(t_filler *f)
{
	get_coords(f, f->yo == 1 ? 'o' : 'x');
	if (where_to)
	ft_printf_fd(2, "\n%d | %d\n", f->px, f->py);
	// while (map[py][px])
	// {
	// 	is
	// }
}

// static int		ft_strategy_up_left(t_info *info)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < info->mapy)
// 	{
// 		j = 0;
// 		while (j < info->mapx)
// 		{
// 			if (ft_try_piece(info, i, j) == 1)
// 			{
// 				info->x = j;
// 				info->y = i;
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }