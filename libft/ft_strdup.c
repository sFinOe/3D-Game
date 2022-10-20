/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:02 by zkasmi            #+#    #+#             */
/*   Updated: 2022/07/18 11:45:07 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;
	char	*nsrc;

	i = 0;
	nsrc = (char *) src;
	len = ft_strlen(nsrc);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (nsrc[i])
	{
		str[i] = nsrc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
