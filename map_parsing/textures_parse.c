/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:50:01 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:14 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

char	*part033(char **cc, char *str, char *line, t_parse *data)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (cc[1][0] == '.')
	{
		while (str[i])
		{
			if (str[i] == '.')
			{
				while (str[i] && str[i] != '\n')
					line[j++] = str[i++];
			}
			i++;
		}
	}
	else
		error(data, "Wrong path to texture\n");
	line[j] = '\0';
	return (line);
}

char	*ft_texture_path(char *str, t_parse *data)
{
	char	*line = NULL;
	char	**cc;

	if(line)
		free(line);
	line = malloc(sizeof(char) * ((ft_strlen(str) - 3) + 1));
	cc = ft_split(str, ' ');
	if (cc[2] != NULL)
		error(data, "Wrong path to texture\n");
	line = part033(cc, str, line, data);
	if (open(line, O_RDWR) == -1 || !ft_strnstr(line, ".xpm", ft_strlen(line)))
		error(data, "Wrong path to texture\n");
	free_char(cc);
	return (line);
}

void	check_double_textures(char *str, t_parse *data, int sep)
{
	if(sep == 1 && !data->no_path)
		data->no_path = ft_texture_path(str, data);
	else if(sep == 2 && !data->so_path)
		data->so_path = ft_texture_path(str, data);
	else if(sep == 3 && !data->we_path)
		data->we_path = ft_texture_path(str, data);
	else if(sep == 4 && !data->ea_path)
		data->ea_path = ft_texture_path(str, data);
	else
		error(data, "Duplicate texture path\n");
}

void	ft_parse_texture(char *str, t_parse *data)
{
	int			i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O')
		check_double_textures(str, data, 1);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		check_double_textures(str, data, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		check_double_textures(str, data, 3);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		check_double_textures(str, data, 4);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W'
		&& str[0] != 'E' && str[0] != 'F' && str[0] != 'C'
		&& str[0] > 65 && str[0] < 122)
		error(data, "Wrong Identifier\n");
}

double	normilize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
