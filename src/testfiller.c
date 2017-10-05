/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfiller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:06:54 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/04 21:06:55 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	return_ex_and_why(t_filler *f)
{
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
	ft_printf("%d %d\n", f->rx, f->ry);
}

static int	where_to_question_mark(t_filler *f)
{
	if (f->where_to == 0)
		return (to_sw(f));
	else if (f->where_to == 1)
		return (to_nw(f));
	else if (f->where_to == 2)
		return (to_se(f));
	else if (f->where_to == 3)
		return (to_ne(f));
	else
		return (0);
}

static void	get_opp_coords(t_filler *f)
{
	int				i;
	int				j;

	i = 0;
	while (i < f->mx)
	{
		j = 0;
		while (j < f->my)
		{
			if (f->map[i][j] == f->toi || f->map[i][j] == f->toi + 32)
			{
				f->ox = i;
				f->oy = i;
			}
			if (f->map[i][j] == f->toi + 32)
				return ;
			j++;
		}
		i++;
	}
}

void		filler(t_filler *f)
{
	get_opp_coords(f);
	if (!where_to_question_mark(f))
		f->ded = 1;
	return_ex_and_why(f);
}
