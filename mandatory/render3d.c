/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:09:13 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/20 20:43:37 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceilling(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H / 2)
		{
			d->main_img.addr[y * WIN_W + x] = \
				rgba(d->parse->cc[0], d->parse->cc[1], d->parse->cc[2]);
			y++;
		}
		while (y < WIN_H)
		{
			d->main_img.addr[y * WIN_W + x] = \
				rgba(d->parse->fc[0], d->parse->fc[1], d->parse->fc[2]);
			y++;
		}
		x++;
	}
}

void	print_walls(int y, int x, t_data *d, char direction)
{
	if (direction == 'E')
		d->main_img.addr[y * WIN_W + x] = \
			d->wall_text[0].addr[d->text_offy * TILE_SIZE + d->text_offx];
	if (direction == 'N')
		d->main_img.addr[y * WIN_W + x] = \
			d->wall_text[0].addr[d->text_offy * TILE_SIZE + d->text_offx];
	if (direction == 'S')
		d->main_img.addr[y * WIN_W + x] = \
			d->wall_text[2].addr[d->text_offy * TILE_SIZE + d->text_offx];
	if (direction == 'W')
		d->main_img.addr[y * WIN_W + x] = \
			d->wall_text[3].addr[d->text_offy * TILE_SIZE + d->text_offx];
}

void	draw_walls(t_data *d, int i)
{
	int	dist_from_top;
	int	y;
	int	x;

	if (d->rays->washit[i] == true)
		d->text_offx = (int)d->rays->wallhity[i] % TILE_SIZE;
	else
		d->text_offx = (int)d->rays->wallhitx[i] % TILE_SIZE;
	y = d->rays->walltoppixel;
	x = i;
	while (y < d->rays->wallbottom_pixel)
	{
		dist_from_top = y + (d->rays->wallstriphight / 2) - (WIN_H / 2);
		d->text_offy = \
			dist_from_top * ((float)TILE_SIZE / d->rays->wallstriphight);
		if (d->rays->washit[i] == false && d->rays->israyup[i])
			print_walls(y, x, d, 'N');
		if (d->rays->washit[i] == true && d->rays->israyleft[i])
			print_walls(y, x, d, 'E');
		if (d->rays->washit[i] == false && d->rays->israydown[i])
			print_walls(y, x, d, 'S');
		if (d->rays->washit[i] == true && d->rays->israyright[i])
			print_walls(y, x, d, 'W');
		y++;
	}
}

void	render_3d(t_data *img)
{
	double	distanceprojectionplane;
	double	wallstriphight;
	double	correctwall;
	int		i;

	distanceprojectionplane = (WIN_W / 2) / tan(FOV / 2);
	draw_floor_ceilling(img);
	i = 0;
	while (i < img->player->num_rays)
	{
		correctwall = img->rays->distance[i] * \
			cos(img->rays->rayangles[i] - img->player->rotationangle);
		wallstriphight = (TILE_SIZE / correctwall) * distanceprojectionplane;
		img->rays->walltoppixel = (WIN_H / 2) - (wallstriphight / 2);
		if (img->rays->walltoppixel < 0)
			img->rays->walltoppixel = 0;
		img->rays->wallbottom_pixel = (WIN_H / 2) + (wallstriphight / 2);
		if (img->rays->wallbottom_pixel > WIN_H)
			img->rays->wallbottom_pixel = WIN_H;
	img->rays->wallstriphight = wallstriphight;
		draw_walls(img, i);
		i++;
	}
}
