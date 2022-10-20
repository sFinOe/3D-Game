/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:13:05 by sayar             #+#    #+#             */
/*   Updated: 2022/10/20 21:09:41 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_next_line(char *lstr)
{
	char	*str;
	int		i;

	i = 0;
	if (!lstr[i])
		return (NULL);
	while (lstr[i] && lstr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (lstr[i] && lstr[i] != '\n')
	{
		str[i] = lstr[i];
		i++;
	}
	if (lstr[i] == '\n')
	{
		str[i] = lstr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_left_str(int fd, char *lstr)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(lstr, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		lstr = ft_strjoin_gnl(lstr, buff);
	}
	free(buff);
	return (lstr);
}

char	*ft_new_lstr(char *lstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lstr[i] && lstr[i] != '\n')
		i++;
	if (!lstr[i])
	{
		free(lstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(lstr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (lstr[i])
		str[j++] = lstr[i++];
	str[j] = '\0';
	free(lstr);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lstr = get_left_str(fd, lstr);
	if (!lstr)
		return (NULL);
	line = ft_next_line(lstr);
	lstr = ft_new_lstr(lstr);
	return (line);
}
