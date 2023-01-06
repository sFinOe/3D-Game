/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:58:50 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 21:23:40 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_export
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	char		**f;
	char		**c;
	char		dir;
	int			playerx;
	int			playery;
	int			map_w;
	int			map_h;
}	t_export;

typedef struct s_map
{
	t_list	*element;
	t_list	*map;
	t_list	*colors;
}	t_map;

typedef struct s_elements
{
	char	*identifier;
	char	*path;
}	t_elements;

//=======================export.c=======================//
t_export	*ft_export(t_export *export, t_elements *elements,
				t_map *data, char **map);

//=======================parse.c=======================//
t_export	*ft_cube(char *str, int fd, t_export *export);
int			player_if_exist(char **str);
void		clear_list(t_list *list);

//=======================parse_colors.c=======================//
int			check_map_colors(t_list *colors, char **tmp);
int			check_color(char **tmp);

//=======================array_func.c=======================//
size_t		ft__array_len(char **str);
void		ft_free_array(char **str);
int			array_size(char *line);
void		ft_free_arr(t_elements *elements);

//=======================errorc=======================//
void		error(char *error);
int			display(char *error);
int			print_error_pos(int row, int column, char c);

//=======================check_map.c=======================//
int			check_map_content(char	**temp, char *charset);
int			check_valid_path(char **map, int i, int j);
int			check_for_error(char **map, int i, int j);

//=======================check_map_elem.c=======================//
int			check_map_elements(t_list *elements, t_elements	**fill);
int			check_textures(t_elements **fill, int i);
int			check_dupes(char *id, t_elements *to_comp, int len);
int			file_if_exist(char *path);

//=======================ft_get_map.c=======================//
t_map		ft_get_map(int fd);
char		*add_to_list(char *line, int i, char *type, t_map *data);
char		*remove_space(char *str);
char		**list_to_array(t_list *lst);

//=======================export_utils.c=======================//
void		get_player_pos(t_export *export);
int			ft_is_player(t_export *export, char c, int i, int j);

#endif