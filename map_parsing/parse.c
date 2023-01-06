/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:58:20 by sayar             #+#    #+#             */
/*   Updated: 2022/10/26 10:34:40 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	player_if_exist(char **str)
{
	int	j;
	int	i;
	int	duplicate;

	i = 0;
	j = 0;
	duplicate = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr("SWEN", str[i][j]))
				duplicate++;
			j++;
		}
		i++;
	}
	if (duplicate != 1)
		return (-1);
	return (0);
}

void	clear_list(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_lst(t_map *data)
{
	clear_list(data->colors);
	clear_list(data->element);
	clear_list(data->map);
}

void	clear(t_map parse_data, char **tmp, t_elements *elements)
{
	ft_lst(&parse_data);
	ft_free_arr(elements);
	ft_free_array(tmp);
}

t_export	*ft_cube(char *str, int fd, t_export *export)
{
	t_elements	*elements;
	char		**tmp;
	t_map		parse_data;

	tmp = NULL;
	elements = malloc(sizeof(t_elements) + 4);
	if (ft_strcmp(str + (ft_strlen(str) - 4), ".cub"))
		return (write(2, "Error\nInvalid Map name\n", 23), NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (write(2, "File doesn't exist\n", 19), NULL);
	parse_data = ft_get_map(fd);
	if (check_map_elements(parse_data.element, &elements) == -1)
		return (NULL);
	if (check_map_colors(parse_data.colors, tmp) == -1)
		return (NULL);
	tmp = list_to_array(parse_data.map);
	if (player_if_exist(tmp) == -1)
		display("Player is Missing/duplicated\n");
	if (check_map_content(tmp, "01SEWN \n") == -1)
		return (NULL);
	export = ft_export(export, elements, &parse_data, \
		list_to_array(parse_data.map));
	clear(parse_data, tmp, elements);
	return (export);
}
