/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:57 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/25 21:19:38 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	alloc_bool(t_data *img)
{
	img->player->wall_strip_w = 1;
	img->player->num_rays = WIN_W / img->player->wall_strip_w;
	img->player->rotationspeed = 2 * (M_PI / 180);
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
	img->player = malloc(sizeof(t_Player));
	img->rays = malloc(sizeof(t_rays));
	img->wall_text = malloc(sizeof(t_img) * 4);
	img->right_arr = 0;
	img->left_arr = 0;
	img->mlx = mlx_init();
	img->win_w = (img->lp * 64);
	img->win_h = (img->hp * 64);
	img->player->x = (double)img->parse->playerx * TILE_SIZE + TILE_SIZE / 2;
	img->player->y = (double)img->parse->playery * TILE_SIZE + TILE_SIZE / 2;
	img->player->turndirection = 0;
	img->player->direction_move = 0;
	img->player->move = 0;
	if (img->parse->dir == 'N')
		img->player->rotationangle = M_PI + (M_PI / 2);
	if (img->parse->dir == 'W')
		img->player->rotationangle = M_PI;
	if (img->parse->dir == 'E')
		img->player->rotationangle = M_PI * 2;
	if (img->parse->dir == 'S')
		img->player->rotationangle = M_PI / 2.01;
	alloc_bool(img);
}

int	is_wall_at(double x, double y, t_data *map)
{
	int	mapgridindexx;
	int	mapgridindexy;

	map->parse->map_w = -1;
	while (map->parse->map[map->parse->map_h - 1][++map->parse->map_w])
		;
	mapgridindexx = (int)floor(x / TILE_SIZE);
	mapgridindexy = (int)floor(y / TILE_SIZE);
	if (mapgridindexx < 0 || mapgridindexx > map->parse->map_w)
		mapgridindexx = 0;
	if (mapgridindexy < 0 || mapgridindexy > map->parse->map_h - 1)
		mapgridindexy = 0;
	if (map->parse->map[mapgridindexy][mapgridindexx] == '0'
			|| ft_strchr("SWEN", map->parse->map[mapgridindexy][mapgridindexx]))
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
