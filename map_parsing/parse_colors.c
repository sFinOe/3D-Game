/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:08:08 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 21:23:27 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_color(char **tmp)
{
	int		j;
	char	*dup;

	j = -1;
	while (tmp[++j])
	{
		dup = ft_strtrim(tmp[j], " \n");
		if (ft_strspn(dup, "0123456789") != ft_strlen(dup))
			return (display("Colors Must Be composed of only Digits"));
		if (ft_atoi(dup) < 0 || ft_atoi(dup) > 255)
			return (display("Colors Must Be in Range [0 => 255]"));
		free(dup);
	}
	if (j != 3)
		return (display("Usage : Ex: [F 220,100,22 || C 220,100,22]"));
	return (0);
}

int	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 3)
		return (1);
	return (0);
}

int	check_map_colors(t_list *colors, char **tmp)
{
	int			i;

	i = 0;
	if (ft_lstsize(colors) != 2)
		return (display("Usage : Ex: [F 220,100,22 || C 220,100,22]\n"));
	while (colors)
	{
		tmp = ft_split((char *)colors->content + 2, ',');
		if (ft__array_len(tmp) != 3 || check_comma((char *)colors->content))
			return (display("Usage : Ex: [F 220,100,22 || C 220,100,22]\n"));
		if (!tmp)
			return (display("Split Error\n"));
		if (check_color(tmp) == -1)
			return (-1);
		ft_free_array(tmp);
		colors = colors->next;
		i++;
	}
	return (0);
}
