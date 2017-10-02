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

static int	is_valid(t_filler *f, int i, int j)
{
	(void)f;
	(void)i;
	(void)j;
	return (0);
}

int			check_piece(t_filler *f, int i, int j)
{
	if (f->where_to == 0 && (i + f->pzx < 0 || j + f->pzy < 0))
		return (0);
	if (f->where_to == 1 && (i + f->pzx < 0 || j + f->pzy < f->my))
		return (0);
	if (f->where_to == 2 && (i + f->pzx < f->mx || j + f->pzy < 0))
		return (0);
	if (f->where_to == 3 && (i + f->pzx < f->mx || j + f->pzy < f->my))
		return (0);
	else
		return (is_valid(f, i, j));
}

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
	get_coords(f, f->moi == 1 ? 'o' : 'x');
	if (!where_to_question_mark(f))
		f->ded = 1;
	ft_printf_fd(2, "\n%d | %d\n", f->px, f->py);
	// while (map[py][px])
	// {
	// 	is
	// }
}
