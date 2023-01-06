/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:13:49 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 13:19:34 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	ft__array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	array_size(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[i] == '\n')
		i--;
	while (line[i] && line[i] != '1' && line[i] != '0' && line[i] == ' ')
		i--;
	return (++i);
}

void	ft_free_arr(t_elements *elements)
{
	int	i;

	i = 0;
	if (!elements)
		return ;
	while (i < 4)
	{
		free(elements[i].identifier);
		i++;
	}
	free(elements);
}
