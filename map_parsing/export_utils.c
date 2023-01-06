/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:36:37 by sayar             #+#    #+#             */
/*   Updated: 2022/10/23 20:05:08 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_is_player(t_export *export, char c, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		export->dir = c;
		export->playerx = j;
		export->playery = i;
		return (1);
	}
	return (0);
}

void	get_player_pos(t_export *export)
{
	int	i;
	int	j;

	i = 0;
	while (export->map[i])
	{
		j = 0;
		while (export->map[i][j])
		{
			if (ft_is_player(export, export->map[i][j], i, j) == 1)
				return ;
			j++;
		}
		i++;
	}
}
