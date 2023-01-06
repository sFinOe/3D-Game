/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:08:03 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/25 21:11:39 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bool_distance(t_data *dt, double h_distance, double v_distance, int i)
{
	if (h_distance < v_distance)
		dt->rays->wallhity[i] = dt->rays->h_wallhity;
	else
		dt->rays->wallhity[i] = dt->rays->v_wallhity;
	if (h_distance < v_distance)
		dt->rays->distance[i] = h_distance;
	else
		dt->rays->distance[i] = v_distance;
	if (v_distance < h_distance)
		dt->rays->washit[i] = true;
	else
		dt->rays->washit[i] = false;
}

void	cast_horizontal_vertical_rays(t_data *dt, int i)
{
	double	h_distance;
	double	v_distance;

	horizontal_rays(dt, i);
	vertical_rays(dt, i);
	if (dt->rays->foundwall_h[i])
		h_distance = calculate_distance(dt->player->x,
				dt->player->y, dt->rays->h_wallhitx, dt->rays->h_wallhity);
	else
		h_distance = MAX_INT;
	if (dt->rays->foundwall_v[i])
		v_distance = calculate_distance(dt->player->x, dt->player->y,
				dt->rays->v_wallhitx, dt->rays->v_wallhity);
	else
		v_distance = MAX_INT;
	if (h_distance < v_distance)
		dt->rays->wallhitx[i] = dt->rays->h_wallhitx;
	else
		dt->rays->wallhitx[i] = dt->rays->v_wallhitx;
	bool_distance(dt, h_distance, v_distance, i);
}

double	calculate_distance(double px, double py, double Ax, double Ay)
{
	double	distance;

	distance = sqrt((Ax - px) * (Ax - px) + (Ay - py) * (Ay - py));
	return (distance);
}

void	ray_direction(t_data *dt, int i)
{
	if (dt->rays->rayangles[i] > 0 && dt->rays->rayangles[i] < M_PI)
		dt->rays->israydown[i] = true;
	else
		dt->rays->israydown[i] = false;
	dt->rays->israyup[i] = !dt->rays->israydown[i];
	if (dt->rays->rayangles[i] < 0.5 * M_PI
		|| dt->rays->rayangles[i] > 1.5 * M_PI)
		dt->rays->israyright[i] = true;
	else
		dt->rays->israyright[i] = false;
	dt->rays->israyleft[i] = !dt->rays->israyright[i];
}

void	cast_rays(t_data *ray)
{
	int	i;

	i = 0;
	ray->rays->rayangle = ray->player->rotationangle - (FOV / 2);
	while (i < ray->player->num_rays)
	{
		ray->player->rotationangle = \
			normilize_angle(ray->player->rotationangle);
		ray->rays->rayangle = normilize_angle(ray->rays->rayangle);
		ray->rays->rayangles[i] = ray->rays->rayangle;
		cast_horizontal_vertical_rays(ray, i);
		ray->rays->rayangle += FOV / ray->player->num_rays;
		i++;
	}
}
