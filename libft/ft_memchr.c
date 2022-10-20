/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:49 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:57:16 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	cc;
	size_t	i;

	i = 0;
	p = (char *) s;
	cc = (char) c;
	while (i < n)
	{
		if (*p == cc)
		{
			return (p);
		}
		p++;
		i++;
	}
	return (0);
}
