/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:00:20 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/25 17:20:37 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_player(t_data *d)
{
	double	x_inc;
	double	y_inc;

	d->player->rotationangle = normilize_angle(d->player->rotationangle);
	x_inc = cos(d->player->rotationangle) * d->player->move \
		+ sin(d->player->rotationangle) * d->player->direction_move;
	y_inc = sin(d->player->rotationangle) * d->player->move - \
	cos(d->player->rotationangle) * d->player->direction_move;
	if (d->right_arr == 1)
		d->player->rotationangle += d->player->rotationspeed;
	if (d->left_arr == 1)
		d->player->rotationangle -= d->player->rotationspeed;
	if (is_wall_at(d->player->x + x_inc, d->player->y, d))
		d->player->x += x_inc;
	if (is_wall_at(d->player->x, d->player->y + y_inc, d))
		d->player->y += y_inc;
	cast_rays(d);
	render_3d(d);
	put_in_map(d->parse->map, d);
	mlx_put_image_to_window(d->mlx, d->win, d->main_img_ptr, 0, 0);
	drawcircle(d->minimap_scale * d->player->x,
		d->minimap_scale * d->player->y, 0xe00d0d, d);
}

int	move_position(int keycode, t_data *dt)
{
	if (keycode == 53)
	{
		ft_free(dt);
		exit(0);
	}
	if (keycode == UP)
		dt->player->move = MOVESPEED;
	if (keycode == DOWN)
		dt->player->move = -MOVESPEED;
	if (keycode == RIGHT_ARR)
		dt->right_arr = 1;
	if (keycode == LEFT_ARR)
		dt->left_arr = 1;
	if (keycode == RIGHT)
		dt->player->direction_move = -MOVESPEED;
	if (keycode == LEFT)
		dt->player->direction_move = MOVESPEED;
	return (0);
}

int	key_release(int keycode, t_data *img)
{
	if (keycode == RIGHT_ARR)
		img->right_arr = 0;
	if (keycode == LEFT_ARR)
		img->left_arr = 0;
	if (keycode == UP)
		img->player->move = 0;
	if (keycode == DOWN)
		img->player->move = 0;
	if (keycode == RIGHT)
		img->player->direction_move = 0;
	if (keycode == LEFT)
		img->player->direction_move = 0;
	return (0);
}
