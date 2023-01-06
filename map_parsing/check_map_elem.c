/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:30:59 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 14:13:17 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	file_if_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

int	check_dupes(char *id, t_elements *to_comp, int len)
{
	int	i;

	i = len;
	while (len >= 0)
	{
		if (!ft_strcmp(to_comp[len].identifier, id))
			return (display("Duplicate Textures\n"));
		len--;
	}
	if (file_if_exist(to_comp[i + 1].path) == -1)
		return (display("File doesn't exist\n"));
	return (0);
}

int	check_textures(t_elements **fill, int i)
{
	if (ft_strcmp((*fill)[i].identifier, "SO")
		&& ft_strcmp((*fill)[i].identifier, "NO")
		&& ft_strcmp((*fill)[i].identifier, "WE")
		&& ft_strcmp((*fill)[i].identifier, "EA"))
		return (display("Invalid Identifier\n"));
	return (0);
}

int	check_map_elements(t_list *elements, t_elements	**fill)
{
	int		start;
	char	*str;
	int		i;

	i = -1;
	if (ft_lstsize(elements) != 4)
		return (display("misconfiguration is encountered in the file\n"));
	while (elements)
	{
		str = (char *)elements->content;
		start = ft_strcspn(str, " ");
		(*fill)[++i].identifier = ft_substr(str, 0, start);
		if (!(*fill)[i].identifier || !(*fill)[i].identifier[0]
			|| !ft_strchr("./abcdefghijklmnopqrstuvwxyz", str[start + 1]))
			return (display("Invalid Identifier\n"));
		if (check_textures(fill, i) == -1)
			return (-1);
		start = ft_strcspn(str, "./abcdefghijklmnopqrstuvwxyz");
		(*fill)[i].path = ft_strchr(str, str[start]);
		if (check_dupes((*fill)[i].identifier, *fill, i - 1) == -1)
			return (-1);
		elements = elements->next;
	}
	return (0);
}
