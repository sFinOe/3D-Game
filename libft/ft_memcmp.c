/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:43 by zkasmi            #+#    #+#             */
/*   Updated: 2021/11/18 12:45:53 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (sr1[i] != sr2[i])
		{
			return (sr1[i] - sr2[i]);
		}
		i++;
	}
	return (0);
}
