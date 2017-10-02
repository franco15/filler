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
	if (f->where_to - 1 == 0)
		f->where_to++;
	else if (f->where_to - 1 == 1)
		f->where_to++;
	else if (f->where_to - 1 == 2)
		f->where_to++;
	else if (f->where_to - 1 == 3)
		f->where_to = 0;
	if (f->ded == 1)
	{
		// ft_printf_fd(2, "\nded\n");
		// ft_printf_fd(2, "%d %d\n", f->rx, f->ry);
		ft_printf("0 0\n");
		return ;
	}
	ft_printf("%d %d\n", f->rx, f->ry);
}

static int	where_to_question_mark_x(t_filler *f)
{
	if (f->where_to == 0)
	{
		f->where_to++;
		if (to_nw(f))
			return (1);
	}
	if (f->where_to == 1)
	{
		f->where_to++;
		if (to_sw(f))
			return (1);
	}
	if (f->where_to == 2)
	{
		f->where_to++;
		if (to_se(f))
			return (1);
	}
	if (f->where_to == 3)
	{
		f->where_to++;
		if (to_ne(f))
			return (1);
	}
	return (0);
}

static int	where_to_question_mark_o(t_filler *f)
{
	if (f->where_to == 0)
	{
		// ft_printf_fd(2, "\n%d", f->where_to);
		f->where_to++;
		if (to_ne(f))
			return (1);
	}
	else if (f->where_to == 1)
	{
		// ft_printf_fd(2, "\n%d", f->where_to);
		f->where_to++;
		if (to_se(f))
			return (1);
	}
	else if (f->where_to == 2)
	{
		// ft_printf_fd(2, "\n%d", f->where_to);
		f->where_to++;
		if (to_sw(f))
			return (1);
	}
	else if (f->where_to == 3)
	{
		// ft_printf_fd(2, "\n%d", f->where_to);
		f->where_to++;
		if (to_nw(f))
			return (1);
	}
	// ft_printf_fd(2, "\nquit\n");
	return (0);
}

void	filler(t_filler *f)
{
	static int	i;

	i = 0;
	// if (i++ > 0)
	// 	get_coords(f, f->moi == 'O' ? 'o' : 'x');
	// else
	// ft_printf_fd(2, "\non filler() b4 get_coords\n");
	get_coords(f);
	// ft_printf_fd(2, "\nx = %d | y = %d\n", f->cx, f->cy);
	if (f->moi == 'O')
	{
		if (!where_to_question_mark_o(f))
		{
			// ft_printf_fd(2, "\ndeeeeeed\n");
			f->ded = 1;
		}
	}
	else
	{
		if (!where_to_question_mark_x(f))
		{
			// ft_printf_fd(2, "\nquiiiiiit\n");
			f->ded = 1;
		}
	}
	return_ex_and_why(f);
}
