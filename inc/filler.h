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
	int			tu;
	int			mx;
	int			my;
	char		**map;
	char		**pz;	
}				t_filler;

/*
** main.c
*/
int		main(int ac, char **av);

#endif
