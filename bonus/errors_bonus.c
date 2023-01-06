/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:19:49 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/25 12:13:10 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_char(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free(t_data *dt)
{
	mlx_destroy_window(dt->mlx, dt->win);
	free(dt->rays->wallhitx);
	free(dt->rays->wallhity);
	free(dt->rays->distance);
	free(dt->rays->rayangles);
	free(dt->rays->israydown);
	free(dt->rays->israyup);
	free(dt->rays->israyleft);
	free(dt->rays->israyright);
	free(dt->rays->foundwall_v);
	free(dt->rays->foundwall_h);
	free(dt->rays->washit);
	free(dt->wall_text);
	free(dt->player);
	free(dt->rays);
	free(dt->parse->ea_path);
	free(dt->parse->we_path);
	free(dt->parse->so_path);
	free(dt->parse->no_path);
	free(dt->parse);
	ft_free_array(dt->parse->f);
	ft_free_array(dt->parse->c);
	free(dt);
}
