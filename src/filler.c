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

static void	return_ex_and_why(t_filler *f)
{
	if (f->where_to == 0)
		f->where_to = 3;
	else if (f->where_to == 1)
		f->where_to++;
	else if (f->where_to == 2)
		f->where_to--;
	else if (f->where_to == 3)
		f->where_to = 0;
	if (f->ded == 1)
	{
		ft_printf("0 0\n");
		return ;
	}
	ft_printf_fd(1, "%d %d\n", f->rx, f->ry);
}

static void	where_to_question_mark_o(t_filler *f)
{
	if (f->where_to == 0)
		to_se(f);
	else if (f->where_to == 1)
		to_nw(f);
	else if (f->where_to == 2)
		to_sw(f);
	else if (f->where_to == 3)
		to_ne(f);
}

void	filler(t_filler *f)
{
	//static int	i;

	//i = 0;
	// if (i++ > 0)
	// 	get_coords(f, f->moi == 'O' ? 'o' : 'x');
	// else
	// ft_printf_fd(2, "\non filler() b4 get_coords\n");
	get_coords(f);
	// ft_printf_fd(2, "\nx = %d | y = %d\n", f->cx, f->cy);
	where_to_question_mark_o(f);
	return_ex_and_why(f);
}
