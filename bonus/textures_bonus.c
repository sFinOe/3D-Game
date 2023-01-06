/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:13:12 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/25 16:04:28 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	img_to_array(t_data *d)
{
	d->wall_text[0].addr = (int *)mlx_get_data_addr(\
		d->wall_text[0].mlx_img, &d->wall_text->bpp, \
	&d->wall_text->line_len, &d->wall_text->endian);
	d->wall_text[1].addr = (int *)mlx_get_data_addr(\
		d->wall_text[1].mlx_img, &d->wall_text->bpp, \
	&d->wall_text->line_len, &d->wall_text->endian);
	d->wall_text[2].addr = (int *)mlx_get_data_addr(\
		d->wall_text[2].mlx_img, &d->wall_text->bpp, \
	&d->wall_text->line_len, &d->wall_text->endian);
	d->wall_text[3].addr = (int *)mlx_get_data_addr(\
		d->wall_text[3].mlx_img, &d->wall_text->bpp, \
	&d->wall_text->line_len, &d->wall_text->endian);
}

void	load_wall(t_data *d)
{
	int	tab[8];

	d->wall_text[0].mlx_img = \
		mlx_xpm_file_to_image(d->mlx, \
	d->parse->ea_path, &tab[0], &tab[1]);
	d->wall_text[1].mlx_img = \
		mlx_xpm_file_to_image(d->mlx, \
	d->parse->no_path, &tab[0], &tab[1]);
	d->wall_text[2].mlx_img = \
		mlx_xpm_file_to_image(d->mlx, \
	d->parse->so_path, &tab[4], &tab[5]);
	d->wall_text[3].mlx_img = \
		mlx_xpm_file_to_image(d->mlx, \
	d->parse->we_path, &tab[6], &tab[7]);
	if (!d->wall_text[0].mlx_img || !d->wall_text[1].mlx_img
		|| !d->wall_text[2].mlx_img || !d->wall_text[3].mlx_img)
		display("Error: Texture\n");
	img_to_array(d);
}

int	rgba(unsigned int red, unsigned int green, unsigned int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	mlx_data(t_data *img)
{
	move_player(img);
	return (0);
}

double	normilize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
