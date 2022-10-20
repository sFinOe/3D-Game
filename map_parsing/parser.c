/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:42:06 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:12 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

t_parse	*init_data(void)
{
	t_parse	*data;

	data = malloc(sizeof(t_parse));
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->f = 0;
	data->c = 0;
	data->size_l = 0;
	data->nbr_line = 0;
	data->i = 0;
	data->indicator_f = 0;
	data->indicator_c = 0;
	data->begin = 'z';
	data->insidemap = 0;
	data->wrong_c = 0;
	data->empty_line = 0;
	data->sum = 0;
	data->error = 0;
	return (data);
}

void	parser(char *file, t_parse *data, t_data *img)
{
	int		fd;
	char	*line;

	line = NULL;
	data = init_data();
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (data->error == 2)
			error(data, "Problems at Parsing\n");
		ft_is_map(line, data);
		set_colors(line, data);
		ft_parse_texture(line, data);
		free(line);
	}
	close(fd);
	if (data->nbr_line == 0 || data->size_l == 0)
		error(data, "Map is missing\n");
	ft_parse_map(file, data);
	check_map(data);
	img->parse = data;
}

int	ft_cube(char *str, t_parse *data, t_data *img)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			write(2, "Error\nInvalid map name\n", 23);
			exit (1);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		parser(str, data, img);
	else
	{
		write(2, "Error\nInvalid map name\n", 23);
		exit(1);
	}
	return (0);
}
