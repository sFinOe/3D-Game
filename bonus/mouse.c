/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:00:20 by zkasmi            #+#    #+#             */
/*   Updated: 2022/07/24 10:50:33 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse(int x, int y, t_data *dt)
{
	static int	old_x;

	(void)y;
	if (x <= WIN_W && x >= 0 && y <= WIN_H && y >= 0 && x < old_x)
		dt->player->rotationangle -= 3 * (M_PI / 180);
	if (x >= 0 && x <= WIN_W && y <= WIN_H && y >= 0 && x > old_x)
		dt->player->rotationangle += 3 * (M_PI / 180);
	old_x = x;
	return (0);
}
