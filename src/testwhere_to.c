#include "filler.h"

int	to_ne(t_filler *f)
{
	int	i;
	int	j;

	i = f->mx;
	while (i > 0)
	{
		j = 0;
		while (j < f->my)
		{
			if (check_piece(f, i, j) == 1)
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int	to_nw(t_filler *f)
{
	int	i;
	int	j;

	i = f->mx;
	while (i > 0)
	{
		j = f->my;
		while (j > 0)
		{
			if (check_piece(f, i, j) == 1)
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	to_se(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->mx)
	{
		j = 0;
		while (j < f->my)
		{
			if (check_piece(f, i, j) == 1)
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);

}

int	to_sw(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->mx)
	{
		j = f->my;
		while (j > 0)
		{
			if (check_piece(f, i, j) == 1)
			{
				f->rx = i;
				f->ry = j;
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}