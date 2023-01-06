/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:42 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 14:27:49 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_for_error(char **map, int i, int j)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0'
		&& !ft_strchr("SEWN", map[i][j + 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j + 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0'
		&& !ft_strchr("SEWN", map[i][j - 1]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i][j - 1])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0'
		&& !ft_strchr("SEWN", map[i + 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i + 1][j])
		return (print_error_pos(i, j, map[i][j]));
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0'
		&& !ft_strchr("SEWN", map[i - 1][j]))
		return (print_error_pos(i, j, map[i][j]));
	if (!map[i - 1][j])
		return (print_error_pos(i, j, map[i][j]));
	return (0);
}

int	check_valid_path(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (map[i][j] == '0')
		if (check_for_error(map, i, j) == -1)
			return (-1);
	if (map[i][j] == ' ')
	{
		if (j - 1 == -1)
			return (0);
	}
	if (ft_strchr("SEWN", map[i][j]))
		if (check_for_error(map, i, j) == 1)
			return (-1);
	return (0);
}

int	check_map_content(char	**temp, char *charset)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		return (display("The map must be closed/surrounded by walls"));
	while (temp[i + 1])
	{
		if (ft_strspn(temp[i], charset) != ft_strlen(temp[i]))
			return (display("Map must Be Composed Of Only '01SEWN'"));
		j = ft_strspn(temp[i], " ");
		if (temp[i][j] != '1')
			return (print_error_pos(i, j, temp[i][j]));
		j = 0;
		while (temp[i][j])
		{
			if (check_valid_path(temp, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		return (display("The map must be closed/surrounded by walls"));
	return (0);
}
