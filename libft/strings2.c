/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:48:37 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/28 11:48:38 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

size_t	ft_strlenc(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s++)
	{
		if (*s == c)
			return (l);
		l++;
	}
	return (l);
}

char	*ft_strcpy(char *dst, const	char *src)
{
	char *p;

	p = dst;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (n-- && s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
