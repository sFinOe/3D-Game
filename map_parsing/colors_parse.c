/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:48:46 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 20:54:00 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

int	count_comma(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

void	ft_atoi_check(char *str, t_parse *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		data->error = 2;
	if (count_comma(str) != 2)
		data->error = 2;
}

int	ft_atoi_color_c(char *str, t_parse *data)
{
	int		res;
	int		ver;

	res = 0;
	ver = 0;
	ft_atoi_check(str, data);
	if (str[1] != ' ')
		error(data, "C element is wrong\n");
	while (str[data->i] == ' ' || str[data->i] == '\t'
		|| str[data->i] == ',' || str[data->i] == '\n')
	{
		data->i++;
		ver = 0;
		if (str[data->i] >= '0' && str[data->i] <= '9')
			data->indicator_c++;
		while (str[data->i] >= '0' && str[data->i] <= '9')
		{
			ver = (ver * 10) + str[data->i] - 48;
			res = (res * 10) + str[data->i] - 48;
			data->i++;
		}
		if (ver > 255)
			error(data, "C elemnt have a digit more that 255\n");
	}
	return (res);
}

int	ft_atoi_color_f(char *str, t_parse *data)
{
	int		res;
	int		ver;

	res = 0;
	ver = 0;
	ft_atoi_check(str, data);
	if (str[1] != ' ')
		error(data, "F element is wrong\n");
	while (str[data->i] == ' ' || str[data->i] == '\t'
		|| str[data->i] == ',' || str[data->i] == '\n')
	{
		data->i++;
		ver = 0;
		if (str[data->i] >= '0' && str[data->i] <= '9')
			data->indicator_f++;
		while (str[data->i] >= '0' && str[data->i] <= '9')
		{
			ver = (ver * 10) + str[data->i] - 48;
			res = (res * 10) + str[data->i] - 48;
			data->i++;
		}
		if (ver > 255)
			error(data, "F elemnt have a digit more that 255");
	}
	return (res);
}

void	set_colors_2(t_parse *data, char *str, char **plit, int i)
{
	if (str[i] == 'C')
	{
		data->c = ft_atoi_color_c(str, data);
		plit = ft_split(str + 2, ',');
		if (data->cc)
			free(data->cc);
		data->cc = malloc(sizeof(int) * 3);
		data->cc[0] = atoi(plit[0]);
		data->cc[1] = atoi(plit[1]);
		data->cc[2] = atoi(plit[2]);
		free_char(plit);
	}
}

void	set_colors(char *str, t_parse *data)
{
	int		i;
	char	**plit;

	plit = NULL;
	i = 0;
	data->i = 1;
	if (data->size_l > 0 && (data->no_path == NULL
			|| data->so_path == NULL || data->we_path == NULL
			|| data->ea_path == NULL))
		error(data, "element is missing\n");
	if (str[i] == 'F')
	{
		data->f = ft_atoi_color_f(str, data);
		plit = ft_split(str + 2, ',');
		if (data->fc)
			free(data->fc);
		data->fc = malloc(sizeof(int) * 3);
		data->fc[0] = atoi(plit[0]);
		data->fc[1] = atoi(plit[1]);
		data->fc[2] = atoi(plit[2]);
		free_char(plit);
	}
	set_colors_2(data, str, plit, i);
}
