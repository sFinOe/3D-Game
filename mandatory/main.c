/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:16:26 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/26 14:34:22 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*img;

	if (ac == 1 || ac > 2)
	{
		write(2, "Error\nUsage : ./Cub3d [map file]\n", 33);
		exit(1);
	}
	img = malloc(sizeof(t_data));
	img->parse = NULL;
	img->parse = ft_cube(av[1], 0, NULL);
	if (!img->parse)
		return (1);
	img->s = img->parse->map;
	count_map(img);
	init(img);
	load_wall(img);
	img->win = mlx_new_window(img->mlx, WIN_W, WIN_H, "Cube3D.exe");
	img->main_img_ptr = mlx_new_image(img->mlx, WIN_W, WIN_H);
	img->main_img.addr = (int *)mlx_get_data_addr(img->main_img_ptr,
			&img->main_img.bpp, &img->main_img.line_len, &img->main_img.endian);
	mlx_hook(img->win, 02, 1L << 0, &move_position, img);
	mlx_hook(img->win, 03, 1L << 1, &key_release, img);
	mlx_loop_hook(img->mlx, &mlx_data, img);
	mlx_hook(img->win, 17, 0, close_win, img);
	mlx_loop(img->mlx);
}
