/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:31 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:57:55 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *)str1;
	s = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (p[i] != s[i] || p[i] == 0 || s[i] == 0)
		{
			return (p[i] - s[i]);
		}
		i++;
	}
	return (0);
}
