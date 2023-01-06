/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:54:06 by sayar             #+#    #+#             */
/*   Updated: 2022/10/26 15:01:26 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	export_colors(t_map *data, t_export *export)
{
	t_list	*temp;

	temp = data->colors;
	while (data->colors)
	{
		if (!ft_strncmp((char *)data->colors->content, "F ", 2))
			export->f = ft_split((char *)data->colors->content, ',');
		else if (!ft_strncmp((char *)data->colors->content, "C ", 2))
			export->c = ft_split((char *)data->colors->content, ',');
		else
			display("Invalid element in the map!\n");
		data->colors = data->colors->next;
	}
	clear_list(temp);
}

int	s_space(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '.')
			return (i);
		i--;
	}
	return (ft_strlen(str));
}

void	check_extention(t_export *export)
{
	if (ft_strncmp(export->no_path + s_space(export->no_path), ".xpm", 4))
		return (write(2, "Error\nWrong file extention\n", 28), exit(1));
	if (ft_strncmp(export->so_path + s_space(export->so_path), ".xpm", 4))
		return (write(2, "Error\nWrong file extention\n", 28), exit(1));
	if (ft_strncmp(export->ea_path + s_space(export->ea_path), ".xpm", 4))
		return (write(2, "Error\nWrong file extention\n", 28), exit(1));
	if (ft_strncmp(export->we_path + s_space(export->we_path), ".xpm", 4))
		return (write(2, "Error\nWrong file extention\n", 28), exit(1));
}

t_export	*ft_export(t_export *export, t_elements *elements,
					t_map *data, char **map)
{
	int	i;

	export = malloc(sizeof(t_export));
	i = -1;
	while (++i < 4)
	{
		if (!ft_strcmp(elements[i].identifier, "SO"))
			export->so_path = ft_strdup(elements[i].path);
		else if (!ft_strcmp(elements[i].identifier, "NO"))
			export->no_path = ft_strdup(elements[i].path);
		else if (!ft_strcmp(elements[i].identifier, "WE"))
			export->we_path = ft_strdup(elements[i].path);
		else if (!ft_strcmp(elements[i].identifier, "EA"))
			export->ea_path = ft_strdup(elements[i].path);
	}
	check_extention(export);
	export->map_w = 0;
	export->map_h = ft_lstsize(data->map);
	export->map = map;
	export_colors(data, export);
	get_player_pos(export);
	return (export);
}
