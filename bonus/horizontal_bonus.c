/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:04:04 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/24 20:26:11 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calcule_horizontal_steps(t_data *dt, int i)
{
	if (dt->rays->israydown[i])
		dt->rays->h_yintercept += TILE_SIZE;
	else
		dt->rays->h_yintercept += 0;
	dt->rays->h_xintercept = dt->player->x
		+ (dt->rays->h_yintercept - dt->player->y)
		/ tan(dt->rays->rayangles[i]);
	dt->rays->ystep = TILE_SIZE;
	if (dt->rays->israyup[i])
		dt->rays->ystep *= -1;
	else
		dt->rays->ystep *= 1;
	dt->rays->xstep = TILE_SIZE / tan(dt->rays->rayangles[i]);
	if (dt->rays->israyleft[i] && dt->rays->xstep > 0)
		dt->rays->xstep *= -1;
	else
		dt->rays->xstep *= 1;
	if (dt->rays->israyright[i] && dt->rays->xstep < 0)
		dt->rays->xstep *= -1;
	else
		dt->rays->xstep *= 1;
}

void	h_distance(double h_nextyinter, double h_nextxinter, t_data *dt, int i)
{
	h_nextyinter = dt->rays->h_yintercept;
	h_nextxinter = dt->rays->h_xintercept;
	while ((h_nextxinter >= 0 && h_nextxinter <= dt->win_w)
		&& (h_nextyinter >= 0 && h_nextyinter <= dt->win_h))
	{
		dt->x_check = h_nextxinter;
		dt->y_check = h_nextyinter;
		if (dt->rays->israyup[i])
			dt->y_check--;
		if (is_wall_at(dt->x_check, dt->y_check, dt) == 0)
		{
			dt->rays->foundwall_h[i] = true;
			dt->rays->h_wallhitx = --h_nextxinter;
			dt->rays->h_wallhity = --h_nextyinter;
			break ;
		}
		else
		{
			h_nextxinter += dt->rays->xstep;
			h_nextyinter += dt->rays->ystep;
		}
	}
}

void	horizontal_rays(t_data *dt, int i)
{
	double	h_nextxinter;
	double	h_nextyinter;

	h_nextxinter = 0;
	h_nextyinter = 0;
	ray_direction(dt, i);
	dt->rays->h_wallhitx = 0;
	dt->rays->h_wallhity = 0;
	dt->rays->foundwall_h[i] = false;
	dt->rays->washit[i] = false;
	dt->rays->h_yintercept = floor(dt->player->y / TILE_SIZE) * TILE_SIZE;
	calcule_horizontal_steps(dt, i);
	h_distance(h_nextyinter, h_nextxinter, dt, i);
}
