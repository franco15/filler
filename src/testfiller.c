#include "filler.h"

/*
** map00 p1 [9, 2] p2 [12, 14]
** map01 p1 [4, 4] p2 [19, 33]
** map02 p1 [30, 31] p2 [70, 71]
*/

static void	return_ex_and_why(t_filler *f)
{
	// if (f->where_to == 0)
	// 	f->where_to = 3;
	// else if (f->where_to == 1)
	// 	f->where_to = 2;
	// else if (f->where_to == 2)
	// 	f->where_to = 1;
	// else if (f->where_to == 3)
	// 	f->where_to = 0;
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
		return (to_ne(f));
	else if (f->where_to == 1)
		return (to_se(f));
	else if (f->where_to == 2)
		return (to_sw(f));
	else if (f->where_to == 3)
		return (to_nw(f));
	else
		return (0);
}

static void	set_coords(t_filler *f, int i, int j)
{
	// f->cx = 0;
	// f->cy = 0;
	// f->ox = 0;
	// f->oy = 0;
	while (++i < f->mx)
	{
		j = -1;
		while (++j < f->my)
		{
			if (f->map[i][j] == f->moi || f->map[i][j] == f->toi)
			{
				if (f->map[i][j] == f->moi && (ft_abs((i + j) - (f->cx + f->cy)) <
				ft_abs((i + j) - (f->ox + f->oy))))
				{
					f->cx = i;
					f->cx = j;
				}
				if (f->map[i][j] == f->toi && (ft_abs((i + j) - (f->cx + f->cy)) <
				ft_abs((i + j) - (f->ox + f->oy))))
				{
					f->ox = i;
					f->oy = j;
				}
			}
		}
	}
}

static void	pre_where_to(t_filler *f)
{
	if (f->ox > f->mx / 2 && f->oy > f->my / 2)
		f->where_to = 0;
	else if (f->ox < f->mx / 2 && f->oy > f->my / 2)
		f->where_to = 1;
	else if (f->ox < f->mx / 2 && f->oy < f->my / 2)
		f->where_to = 2;
	else if (f->ox > f->mx / 2 && f->oy < f->my / 2)
		f->where_to = 3;
}

void	filler(t_filler *f)
{
	set_coords(f, -1, -1);
	pre_where_to(f);
	if (!where_to_question_mark(f))
		f->ded = 1;
	return_ex_and_why(f);
}
