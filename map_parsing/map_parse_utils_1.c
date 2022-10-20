/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:53:40 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:05 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

size_t	ft_strspn(const char *str, char *charset)
{
	int	i;

	i = 0;
	if (str == NULL || charset == NULL)
		return (i);
	while (str[i] && ft_strchr(charset, str[i]))
		i++;
	return (i);
}

int	ft_start(char c, t_parse *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->begin != 'z')
			error(data, "more than one player\n");
		data->begin = c;
		data->playerx = i;
		data->playery = j;
		return (1);
	}
	return (0);
}

size_t	ft_arr_langth(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_bottom_path(char **map, int i, int j)
{
	while (i < (int)ft_arr_langth(map) - 1)
	{
		if (i - 1 < 0)
			break ;
		if (map[i][j] == '0'
			&& (map[i + 1][j] == ' ' || !map[i + 1][j] || map[i][j] == '\t'))
		{
			print_error_pos(i, j, map[i][j]);
			return (-1);
		}
		if ((map[i][j] == ' ' || map[i][j] == '\t') && (map[i + 1][j] == '0'))
		{
			print_error_pos(i, j, map[i][j]);
			return (-1);
		}
		if (map[i + 1][j] == '1')
			break ;
		i--;
	}
	return (0);
}

void	ft_is_map(char *str, t_parse *data)
{
	int			i;
	static int	nbr_line = 0;
	static int	line_size = 0;

	i = 0;
	if (valid_map(str, data) == 1)
	{
		i = ft_strlen(str);
		if (i > line_size)
			line_size = i;
		nbr_line += 1;
	}
	data->nbr_line = nbr_line;
	data->size_l = line_size;
}
