#include "filler.h"

int	to_ne(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	i = f->mx;
	d = f->mx + f->my;
	while (i > 0)
	{
		j = -f->pzy;
		while (j < f->my)
		{
			if (check_piece(f, i, j) == 1)
			{
				if (ft_abs((i + j) - (f->ox + f->oy)) < d)
				{
					f->rx = i;
					f->ry = j;
					d = ft_abs((i + j) - (f->ox + f->oy));
				}
			}
			j++;
		}
		i--;
	}
	return (d != f->mx + f->my ? 1 : 0);
}

int	to_nw(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	i = f->mx;
	d = f->mx + f->my;
	while (i > 0)
	{
		j = f->my;
		while (j > 0)
		{
			if (check_piece(f, i, j) == 1)
			{
				if (ft_abs((i + j) - (f->ox + f->oy)) < d)
				{
					f->rx = i;
					f->ry = j;
					d = ft_abs((i + j) - (f->ox + f->oy));
				}
			}
			j--;
		}
		i--;
	}
	return (d != f->mx + f->my ? 1 : 0);
}

int	to_se(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	i = -f->pzx;
	d = f->mx + f->my;
	while (i < f->mx)
	{
		j = -f->pzy;
		while (j < f->my)
		{
			if (check_piece(f, i, j) == 1)
			{
				if (ft_abs((i + j) - (f->ox + f->oy)) < d)
				{
					f->rx = i;
					f->ry = j;
					d = ft_abs((i + j) - (f->ox + f->oy));
				}
			}
			j++;
		}
		i++;
	}
	return (d != f->mx + f->my ? 1 : 0);

}

int	to_sw(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	i = -f->pzx;
	d = f->mx + f->my;
	while (i < f->mx)
	{
		j = f->my;
		while (j > 0)
		{
			if (check_piece(f, i, j) == 1)
			{
				if (ft_abs((i + j) - (f->ox + f->oy)) < d)
				{
					f->rx = i;
					f->ry = j;
					d = ft_abs((i + j) - (f->ox + f->oy));
				}
			}
			j--;
		}
		i++;
	}
	return (d != f->mx + f->my ? 1 : 0);
}
