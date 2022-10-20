/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:00:20 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/20 20:57:54 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_player(t_data *d)
{
	double	x_inc;
	double	y_inc;

	d->player->rotationangle = normilize_angle(d->player->rotationangle);
	x_inc = cos(d->player->rotationangle) * d->player->up_move \
		+ sin(d->player->rotationangle) * d->player->right_move;
	y_inc = sin(d->player->rotationangle) * d->player->up_move - \
	cos(d->player->rotationangle) * d->player->right_move;
	if (d->up_right == 1)
		d->player->rotationangle += d->player->rotationspeed;
	if (d->up_left == 1)
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
		dt->player->up_move = MOVESPEED;
	if (keycode == DOWN)
		dt->player->up_move = -MOVESPEED;
	if (keycode == RIGHT_ARR)
		dt->up_right = 1;
	if (keycode == LEFT_ARR)
		dt->up_left = 1;
	if (keycode == RIGHT)
		dt->player->right_move = -MOVESPEED;
	if (keycode == LEFT)
		dt->player->right_move = MOVESPEED;
	return (0);
}

int	key_release(int keycode, t_data *img)
{
	if (keycode == RIGHT_ARR)
		img->up_right = 0;
	if (keycode == LEFT_ARR)
		img->up_left = 0;
	if (keycode == UP)
		img->player->up_move = 0;
	if (keycode == DOWN)
		img->player->up_move = 0;
	if (keycode == RIGHT)
		img->player->right_move = 0;
	if (keycode == LEFT)
		img->player->right_move = 0;
	return (0);
}
