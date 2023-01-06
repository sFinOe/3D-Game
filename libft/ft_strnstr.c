/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:19 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/17 18:57:58 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*myp;
	char	*beman;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	myp = (char *)haystack;
	beman = (char *)needle;
	if (ft_strlen(needle) == 0 || haystack == needle)
	{
		return (myp);
	}
	while (myp[i] && i < len)
	{
		while (myp[i + j] == beman[j] && beman[j])
			j++;
		if (i + j > len)
			return (0);
		else if (beman[j] == '\0')
			return (myp + i);
		j = 0;
		i++;
	}
	return (0);
}
