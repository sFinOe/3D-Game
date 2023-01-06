/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:11:07 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/20 21:11:35 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mini_map_floor_color(t_data *img, int i, int j)
{
	while (i < img->xi)
	{
		if (img->yi == 0)
		{
			img->yi = 8;
			j = 0;
		}
		else
			j = img->yi - 8;
		while (j < img->yi)
		{
			img->main_img.addr[(j * WIN_W + i)] = 0xffffff;
			j++;
		}
		i++;
	}
}

void	mini_map_celling_color(t_data *img, int i, int j)
{
	while (i < img->xi)
	{
		if (img->yi == 0)
		{
			img->yi = 8;
			j = 0;
		}
		else
			j = img->yi - 8;
		while (j < img->yi)
		{
			img->main_img.addr[(j * WIN_W + i)] = 0x000000;
			j++;
		}
		i++;
	}
}
