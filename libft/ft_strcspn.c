/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:22:42 by sayar             #+#    #+#             */
/*   Updated: 2022/10/22 13:49:55 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *str, char *charset)
{
	int	i;

	i = 0;
	if (!str || !charset)
		return (i);
	while (str[i] && !ft_strchr(charset, str[i]))
		i++;
	return (i);
}
