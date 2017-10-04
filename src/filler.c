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
	// ft_printf_fd(2, "%d %d\n", f->rx, f->ry);
	if (f->where_to == 0)
		f->where_to = 3;
	else if (f->where_to == 1)
		f->where_to = 2;
	else if (f->where_to == 2)
		f->where_to = 1;
	else if (f->where_to == 3)
		f->where_to = 0;
	if (f->ded == 1)
	{
		ft_printf("0 0\n");
		return ;
	}
	ft_printf_fd(1, "%d %d\n", f->rx, f->ry);
}

static int	where_to_question_mark(t_filler *f)
{
	if (f->where_to == 0)
		return (to_se(f));
	else if (f->where_to == 1)
		return (to_nw(f));
	else if (f->where_to == 2)
		return (to_sw(f));
	else if (f->where_to == 3)
		return (to_ne(f));
	else
		return (0);
}

void	filler(t_filler *f)
{
	if (!where_to_question_mark(f))
		f->ded = 1;
	return_ex_and_why(f);
}
