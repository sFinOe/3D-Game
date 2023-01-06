/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:48 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/18 16:45:43 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	zdst;
	size_t	i;
	size_t	zsrc;

	i = 0;
	zdst = ft_strlen(dst);
	zsrc = ft_strlen(src);
	if (size == 0)
		return (zsrc);
	while (src[i] && ((zdst + i) < (size - 1)))
	{
		dst[i + zdst] = src[i];
		i++;
	}
	dst[zdst + i] = '\0';
	if (size > zdst)
		return (zdst + zsrc);
	return (size + zsrc);
}
