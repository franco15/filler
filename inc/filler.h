/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:33:14 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 10:33:16 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/minilibft.h"

typedef struct	s_filler
{
	int			moi;
	int			toi;
	int			cx;
	int			cy;
	int			mx;
	int			my;
	int			pzx;
	int			pzy;
	int			rx;
	int			ry;
	int			ded;
	// int			opposx;
	// int			opposy;
	int			where_to;
	char		**map;
	char		**pz;
}				t_filler;

/*
** filler.c
*/
void	filler(t_filler *f);

/*
** main.c
*/
int		main(int ac, char **av);

/*
** to_ne.c
*/
int	to_ne(t_filler *f);

/*
** to_nw.c
*/
int	to_nw(t_filler *f);

/*
** to_se.c
*/
int	to_sw(t_filler *f);

/*
** to_se.c
*/
int	to_se(t_filler *f);

/*
** utils.c
*/
void	get_coords(t_filler *f);
void	del_map(t_filler *f);

#endif
