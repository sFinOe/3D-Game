/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:15:19 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/21 16:51:54 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcule_vertical_steps(t_data *dt, int i)
{
	if (dt->rays->israyright[i])
		dt->rays->v_xintercept += TILE_SIZE;
	else
		dt->rays->v_xintercept += 0;
	dt->rays->v_yintercept = dt->player->y + \
		(dt->rays->v_xintercept - dt->player->x) * tan(dt->rays->rayangles[i]);
	dt->rays->xstep = TILE_SIZE;
	if (dt->rays->israyleft[i])
		dt->rays->xstep *= -1;
	else
		dt->rays->xstep *= 1;
	dt->rays->ystep = TILE_SIZE * tan(dt->rays->rayangles[i]);
	if (dt->rays->israyup[i] && dt->rays->ystep > 0)
		dt->rays->ystep *= -1;
	else
		dt->rays->ystep *= 1;
	if (dt->rays->israydown[i] && dt->rays->ystep < 0)
		dt->rays->ystep *= -1;
	else
		dt->rays->ystep *= 1;
}

void	v_distance(double v_nextyinter, double v_nextxinter, t_data *dt, int i)
{
	v_nextyinter = dt->rays->v_yintercept;
	v_nextxinter = dt->rays->v_xintercept;
	while ((v_nextxinter >= 0 && v_nextxinter <= dt->win_w)
		&& (v_nextyinter >= 0 && v_nextyinter <= dt->win_h))
	{
		dt->x_check = v_nextxinter;
		dt->y_check = v_nextyinter;
		if (dt->rays->israyleft[i])
			dt->x_check--;
		if (is_wall_at(dt->x_check, dt->y_check, dt) == 0)
		{
			dt->rays->foundwall_v[i] = true;
			dt->rays->v_wallhitx = --v_nextxinter;
			dt->rays->v_wallhity = --v_nextyinter;
			break ;
		}
		else
		{
			v_nextxinter += dt->rays->xstep;
			v_nextyinter += dt->rays->ystep;
		}
	}
}

void	vertical_rays(t_data *dt, int i)
{
	double	v_nextxinter;
	double	v_nextyinter;

	v_nextxinter = 0;
	v_nextyinter = 0;
	ray_direction(dt, i);
	dt->rays->v_wallhitx = 0;
	dt->rays->v_wallhity = 0;
	dt->rays->foundwall_v[i] = false;
	dt->rays->washit[i] = false;
	dt->rays->v_xintercept = floor(dt->player->x / TILE_SIZE) * TILE_SIZE;
	calcule_vertical_steps(dt, i);
	v_distance(v_nextxinter, v_nextyinter, dt, i);
}
