/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:41 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:57:49 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*p;
	char	*s;

	p = (char *)src;
	s = (char *)dst;
	i = 0;
	if (dstsize > 0)
	{
		while (p[i] && i < (dstsize - 1))
		{
			s[i] = p[i];
			i++;
		}
		s[i] = '\0';
	}
	return (ft_strlen(p));
}
