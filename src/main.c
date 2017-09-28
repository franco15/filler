/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:41:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 10:41:04 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int ac, char **av)
{
	int	i;
	int	j;
	char	*tmp;

	(void)ac;
	(void)av;
	i = 1;
	j = 2;
	ft_printf_fd(2, "--------------------------------\n");
	while (i)
	{
		i = get_next_line(0, &tmp);
		if (j-- > 0)
			continue ;
		ft_putstr_fd(tmp, 2);
		ft_putchar_fd('\n', 2);
	}
	ft_printf_fd(2, "||||||||||||||||||||||||||||||||\n");
	return (0);
}
