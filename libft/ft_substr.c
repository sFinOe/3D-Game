/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:38:43 by zkasmi            #+#    #+#             */
/*   Updated: 2022/07/18 11:48:10 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		start = ft_strlen(s);
		len = 0;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[start + i];
			i++;
	}
	tab[i] = '\0';
	return (tab);
}
