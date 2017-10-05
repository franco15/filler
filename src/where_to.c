/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:59:42 by lfranco-          #+#    #+#             */
/*   Updated: 2017/10/02 10:59:43 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	to_ne(t_filler *f)
{
	int	i;
	int	j;

	i = f->mx;
	while (i > -f->pzx)
	{
		j = -f->pzy;
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
	while (i > -f->pzx)
	{
		j = f->my;
		while (j > -f->pzy)
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

	i = -f->pzx;
	while (i < f->mx)
	{
		j = -f->pzy;
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

	i = -f->pzx;
	while (i < f->mx)
	{
		j = f->my;
		while (j > -f->pzy)
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
