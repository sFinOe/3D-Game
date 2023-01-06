/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:37 by zkasmi            #+#    #+#             */
/*   Updated: 2022/06/12 17:23:44 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*p;
	char	*j;

	p = (char *)s1;
	j = (char *)s2;
	i = 0;
	if (p == NULL && j == NULL)
	{
		return (0);
	}
	while (i < n)
	{
		p[i] = j[i];
		i++;
	}
	return (p);
}
