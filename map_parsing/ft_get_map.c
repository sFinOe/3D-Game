/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:34:20 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 15:40:59 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**list_to_array(t_list *lst)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * ft_lstsize(lst) + 1);
	if (!tmp)
		return (NULL);
	while (lst)
	{
		tmp[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*remove_space(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			j = i;
			i = ft_strspn(str + i, " ");
			i += j - 1;
			while (str[i] && str[i] != '\n')
				str[j++] = str[i++];
			str[j] = '\0';
			tmp = ft_strdup(str);
			return (tmp);
		}
		i++;
	}
	return (str);
}

char	*add_to_list(char *str, int i, char *type, t_map *data)
{
	if (ft_strchr("NSWE", str[i]))
	{
		type = "element";
		ft_lstadd_back(&data->element, ft_lstnew(remove_space(str + i)));
	}
	else if (ft_strchr("FC", str[i]))
	{
		type = "element";
		ft_lstadd_back(&data->colors, ft_lstnew(remove_space(str + i)));
	}
	else if (ft_strchr("01SEWN ", str[i]))
	{
		type = "map";
		ft_lstadd_back(&data->map,
			ft_lstnew(ft_substr(str, 0, array_size(str))));
	}
	else if (ft_strspn(str, " \n") == ft_strlen(str) && ft_strcmp(str, "\n"))
		display("misconfiguration is encountered in the file");
	else if (str[i] != '\n' || (!ft_strcmp(type, "map") && str[i] == '\n'))
		display("misconfiguration is encountered in the file");
	return (type);
}

int	check_last_in_map(char *old_line)
{
	int	i;

	i = -1;
	while (old_line[++i])
		if (!ft_strchr("1 ", old_line[i]))
			return (1);
	return (0);
}

t_map	ft_get_map(int fd)
{
	t_map	data;
	char	*str;
	char	*type;
	char	*old_line;

	data = (t_map){};
	old_line = ft_strdup("");
	while (1)
	{
		str = get_next_line(fd);
		if (!str && ft_strchr(old_line, '\n'))
			display("misconfiguration is encountered in the file");
		if (str == NULL)
			break ;
		free(old_line);
		old_line = ft_strdup(str);
		type = add_to_list(str, ft_strspn(str, " "), type, &data);
		free(str);
	}
	if (check_last_in_map(old_line))
		display("misconfiguration is encountered in the file");
	free(old_line);
	return (data);
}
