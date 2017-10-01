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

void	to_nw(t_filler *f)
{
	int	i;
	int	j;

	i = f->px;
	while (i >= 0)
	{
		j = f->py;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return ;
			}
			j--;
		}
		i--;
	}
}

void	to_ne(t_filler *f)
{
	int	i;
	int	j;

	i = f->px;
	while (i >= 0)
	{
		j = f->py;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return ;
			}
			j++;
		}
		i--;
	}
}

void	to_sw(t_filler *f)
{
	int	i;
	int	j;

	i = f->px;
	while (i >= 0)
	{
		j = f->py;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return ;
			}
			j--;
		}
		i++;
	}
}

void	to_se(t_filler *f)
{
	int	i;
	int	j;

	i = f->px;
	while (i >= 0)
	{
		j = f->py;
		while (j >= 0)
		{
			if (check_piece(f, i, j))
			{
				f->rx = i;
				f->ry = j;
				return ;
			}
			j++;
		}
		i++;
	}

}
