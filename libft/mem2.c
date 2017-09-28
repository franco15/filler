/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:44:56 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 11:44:56 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	*ft_realloc(void *ptr, size_t size, size_t newsize)
{
	void	*new;

	if (ptr && newsize && size)
	{
		new = ft_memalloc(newsize);
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	else
		new = ft_memalloc(newsize);
	return (new);
}
