/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/20 20:38:12 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	alloc_bool(t_data *img)
{
	img->player->wall_strip_w = 1;
	img->player->num_rays = WIN_W / img->player->wall_strip_w;
	img->player->rotationspeed = 1 * (M_PI / 180);
	img->rays->wallhitx = malloc(sizeof(double) * img->player->num_rays);
	img->rays->wallhity = malloc(sizeof(double) * img->player->num_rays);
	img->rays->rayangle = 0;
	img->rays->distance = malloc(sizeof(double) * img->player->num_rays);
	img->rays->rayangles = malloc(sizeof(double) * img->player->num_rays);
	img->rays->israydown = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->israyup = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->israyleft = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->israyright = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->foundwall_v = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->foundwall_h = malloc(sizeof(bool) * img->player->num_rays);
	img->rays->washit = malloc(sizeof(bool) * img->player->num_rays);
	img->minimap_scale = 0.35;
}

void	init(t_data *img)
{
	img->up_right = 0;
	img->up_left = 0;
	img->mlx = mlx_init();
	img->win_w = (img->lp * 64);
	img->win_h = (img->hp * 64);
	img->player->x = img->parse->playery * TILE_SIZE;
	img->player->y = img->parse->playerx * TILE_SIZE;
	img->player->turndirection = 0;
	img->player->right_move = 0;
	img->player->up_move = 0;
	if (img->parse->begin == 'S')
		img->player->rotationangle = M_PI + (M_PI / 2);
	if (img->parse->begin == 'W')
		img->player->rotationangle = M_PI;
	if (img->parse->begin == 'E')
		img->player->rotationangle = M_PI * 2;
	if (img->parse->begin == 'N')
		img->player->rotationangle = M_PI / 2.01;
	alloc_bool(img);
}

int	is_wall_at(double x, double y, t_data *map)
{
	int	mapgridindexx;
	int	mapgridindexy;

	mapgridindexx = (int)floor(x / TILE_SIZE);
	mapgridindexy = (int)floor(y / TILE_SIZE);
	if (map->s[mapgridindexy][mapgridindexx] == '0')
		return (1);
	return (0);
}

void	count_map(t_data *img)
{
	int	j;

	j = 0;
	img->lp = 0;
	img->hp = 0;
	while (img->parse->map[img->hp])
	{
		j = 0;
		while (img->parse->map[img->hp][j])
		{
			if (img->parse->map[img->hp][j] == ' ')
				img->parse->map[img->hp][j] = '1';
			j++;
		}
		if (j > img->lp)
			img->lp = j;
		img->hp++;
	}
}

int	close_win(t_data *data)
{
	ft_free(data);
	exit (0);
}
