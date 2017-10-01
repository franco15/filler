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
	int			yo;
	int			mx;
	int			my;
	int			px;
	int			py;
	int			rx;
	int			ry;
	int			where_to;
	char		**map;
	char		**pz;
}				t_filler;

/*
** filler.c
*/
int		is_valid(t_filler *f);
void	filler(t_filler *f);

/*
** main.c
*/
int		main(int ac, char **av);

/*
** utils.c
*/
void	get_coords(t_filler *f, char c);
void	get_init_coords(t_filler *f);
void	put_first_piece(t_filler *f);

/*
** where_to_question_mark.c
*/
void	to_nw(t_filler *f);
void	to_ne(t_filler *f);
void	to_sw(t_filler *f);
void	to_se(t_filler *f);

#endif
