/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:00:20 by zkasmi            #+#    #+#             */
/*   Updated: 2022/07/24 10:50:33 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

void	draw_map_floor(char s, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	if (img->xi == 0)
	{
		i = 0;
		img->xi = 8;
	}
	else
		i = img->xi - 8;
	if (s == '0')
	{
		mini_map_floor_color(img, i, j);
	}
}

void	draw_map_celling(char s, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	if (img->xi == 0)
	{
		i = 0;
		img->xi = 8;
	}
	else
		i = img->xi - 8;
	if (s == '1' )
	{
		mini_map_celling_color(img, i, j);
	}
	if (img->xi == 0 && img->yi == 0)
	{
		img->xi = 0;
		img->yi = 0;
	}
}

int	draw_mini_map(t_data *img, char s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (img->xi == 0)
	{
		i = 0;
		img->xi = 8;
	}
	else
		i = img->xi - 8;
	draw_map_floor(s, img);
	draw_map_celling(s, img);
	return (0);
}

void	put_in_map(char **s, t_data *img)
{
	img->mapi = 0;
	img->yi = 0;
	while (s[img->mapi])
	{
		img->mapj = 0;
		img->xi = 0;
		while (s[img->mapi][img->mapj])
		{
			if (s[img->mapi][img->mapj] == '1')
				draw_mini_map(img, '1');
			else if (s[img->mapi][img->mapj] == '0'
				|| ft_strchr("SWNE", s[img->mapi][img->mapj]))
				draw_mini_map(img, '0');
			img->mapj++;
			img->xi += 8;
		}
		img->mapi++;
		img->yi += 8;
	}
}
