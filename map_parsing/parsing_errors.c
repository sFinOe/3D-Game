/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:54:26 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:02 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

int	display(char *error)
{
	printf("Error\n%s\n", error);
	return (-1);
}

int	print_error_pos(int row, int column, char c)
{
	printf("row : [%d] colmn : [%d] char : [%c]\n", row, column, c);
	return (-1);
}

void	error(t_parse *data, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
	exit (1);
}

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
