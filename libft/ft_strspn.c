/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:23:48 by sayar             #+#    #+#             */
/*   Updated: 2022/10/22 13:24:17 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str, char *charset)
{
	int	i;

	i = 0;
	if (str == NULL || charset == NULL)
		return (i);
	while (str[i] && ft_strchr(charset, str[i]))
		i++;
	return (i);
}
