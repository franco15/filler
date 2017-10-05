#include "filler.h"

static int	is_valid(t_filler *f, int i, int j)
{
	int	x;
	int	y;
	int	piece;

	x = -1;
	piece = 0;
	while (++x < f->pzx)
	{
		y = -1;
		while (++y < f->pzy)
		{
			if ((x + i >= f->mx || y + j >= f->my || x + i < 0 || y + j < 0) &&
			f->pz[x][y] == '*')
				return (0);
			else if ((x + i >= f->mx || y + j >= f->my || x + i < 0 ||
			y + j < 0) && f->pz[x][y] == '.')
				continue ;
			if ((f->map[x + i][y + j] == f->moi ||
			f->map[x + i][y + j] == f->moi + 32) && f->pz[x][y] == '*')
				piece++;
			else if ((f->map[x + i][y + j] == f->toi ||
			f->map[x + i][y + j] == f->toi + 32) && f->pz[x][y] == '*')
				return (0);
		}
	}
	return (piece == 1 ? 1 : 0);
}

int	check_piece(t_filler *f, int i, int j)
{
	if (i > f->mx)
		return (0);
	else if (j > f->my)
		return (0);
	else
		return (is_valid(f, i, j));
}

void	del_map(t_filler *f)
{
	int	i;

	i = 0;
	while (i < f->mx)
		ft_memdel((void**)&f->map[i++]);
	i = 0;
	while (i < f->pzx)
		ft_memdel((void**)&f->pz[i++]);
}

void	get_coords(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while(i < f->mx)
	{
		j = 0;
		while (j < f->my)
		{
			if (f->map[i][j] == f->moi || f->map[i][j] == f->moi + 32)
			{
				f->cx = i;
				f->cy = i;
			}
			if (f->map[i][j] == f->toi || f->map[i][j] == f->toi + 32)
			{
				f->ox = i;
				f->oy = i;
			}
			j++;
		}
		i++;
	}
	f->where_to = f->cx > f->ox ? 1 : 0;
}
