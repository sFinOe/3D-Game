/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:46:20 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:10 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

int	ft_copy_map(char *line, t_parse *data)
{
	static int	i = 0;
	int			j;

	j = 0;
	data->map[i] = NULL;
	data->map[i] = (char *)malloc(sizeof(char) * (data->size_l + 1));
	if (!data->map[i])
		return (1);
	while (line[j] != '\0' && line[j] != '\n')
	{
		if (ft_start(line[j], data, i, j) == 1)
			data->map[i][j] = '0';
		else if (line[j] == ' ')
			data->map[i][j] = ' ';
		else
			data->map[i][j] = line[j];
		j++;
	}
	while (j <= (data->size_l - 1))
	{
		data->map[i][j] = ' ';
		j++;
	}
	data->map[i][j] = '\0';
	i++;
	if (i == data->nbr_line)
		data->map[i] = NULL;
	return (0);
}

void	check_map(t_parse *data)
{
	if (data->empty_line == 1)
		error(data, "Empty line on the map\n");
	if (check_map_content(data->map, "01SEWN \n") == -1)
		error(data, "Error at the map\n");
	if (data->begin == 'z')
		error(data, "No player on the map\n");
	if (data->indicator_f != 3 || data->indicator_c != 3)
		error(data, "Wrong Input with C or F\n");
	if (data->wrong_c == 1)
		error(data, "Wrong character on the map\n");
}

int	ft_parse_map(char *str, t_parse *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(str, O_RDONLY);
	if(data->map)
		free_char(data->map);
	data->map = (char **)malloc(sizeof(char *) * data->nbr_line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (data->insidemap == 1 && (ft_strspn(line, " \n") == ft_strlen(line))
			&& data->sum < data->nbr_line)
			data->empty_line = 1;
		data->insidemap = valid_map(line, data);
		if (data->insidemap == 1)
		{
			data->sum++;
			ft_copy_map(line, data);
		}
		free(line);
	}
	close(fd);
	// int i = 0;
	// while (data->map[i++])
	// 	printf("%s\n", data->map[i]);
	return (0);
}

int	ft_strchr_map(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	valid_map(char *str, t_parse *data)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (ft_strchr_map(str, '1') == 1)
	{
		while (str[i])
		{
			if (str[i] == 32)
				return (1);
			if (str[i] != '0' && str[i] != '1'
				&& str[i] != 'N' && str[i] != 'W' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != '\n')
			{
				if (data->insidemap == 1)
					data->wrong_c = 1;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
