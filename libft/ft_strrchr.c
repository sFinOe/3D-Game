/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:09 by zkasmi            #+#    #+#             */
/*   Updated: 2021/12/28 18:01:50 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*holder;

	holder = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			holder = (char *)s + i;
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		holder = (char *)s + i;
	}
	return (holder);
}

int	ft_location(char *s, int c)
{
	int		i;
	char	holder;

	i = 0;
	holder = (char )c;
	if (holder == '\0')
	{
		while (s[i])
			i++;
		return (i);
	}
	while (s[i])
	{
		if (s[i] == holder)
			return (i);
		i++;
	}
	return (0);
}
