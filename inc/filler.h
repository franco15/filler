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

# include "../libft/minilibft.h"

typedef struct	s_filler
{
	char		moi;
	char		toi;
	int			cx;
	int			cy;
	int			ox;
	int			oy;
	int			mx;
	int			my;
	int			pzx;
	int			pzy;
	int			rx;
	int			ry;
	int			ded;
	int			d;
	int			where_to;
	char		**map;
	char		**pz;
}				t_filler;

/*
** filler.c
*/
void			filler(t_filler *f);

/*
** main.c
*/
int				main(void);

/*
** utils.c
*/
void			del_map(t_filler *f);
int				check_piece(t_filler *f, int i, int j);
void			get_coords(t_filler *f);

/*
** where_to.c
*/
int				to_ne(t_filler *f);
int				to_nw(t_filler *f);
int				to_sw(t_filler *f);
int				to_se(t_filler *f);

#endif
