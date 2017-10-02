/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_to_question_mark.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 02:37:35 by coco              #+#    #+#             */
/*   Updated: 2017/10/01 02:37:37 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	to_nw(t_filler *f)
{
	int	i;
	int	j;

	i = f->cx;
	while (i >= 0)
	{
		j = f->cy;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
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

int	to_ne(t_filler *f)
{
	int	i;
	int	j;

	i = f->cx;
	while (i >= 0)
	{
		j = f->cy;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
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

int	to_sw(t_filler *f)
{
	int	i;
	int	j;

	i = f->cx;
	while (i >= 0)
	{
		j = f->cy;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
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

int	to_se(t_filler *f)
{
	int	i;
	int	j;

	i = f->cx;
	while (i >= 0)
	{
		j = f->cy;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
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
