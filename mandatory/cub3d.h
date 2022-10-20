/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:53:09 by zkasmi            #+#    #+#             */
/*   Updated: 2022/10/20 20:43:38 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include <mlx.h>
# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define TILE_SIZE 64
# define MAX_INT 2147483647
# define FOV 1.04666666
# define WIN_W 1280
# define WIN_H 720
# define MOVESPEED 3

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define UP_ARR 126
# define DOWN_ARR 125
# define RIGHT_ARR 124
# define LEFT_ARR 123

typedef struct s_parse
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		**map;
	int			f;
	int			c;
	int			size_l;
	int			nbr_line;
	int			i;
	int			indicator_c;
	int			indicator_f;
	char		begin;
	int			playerx;
	int			playery;
	int			insidemap;
	int			wrong_c;
	int			empty_line;
	int			sum;
	int			error;
	int			*fc;
	int			*cc;
}	t_parse;

typedef struct s_player
{
	double	x;
	double	y;
	double	fx;
	double	fy;
	double	radius;
	int		turndirection;
	int		walkdirection;
	int		up_move;
	int		right_move;
	int		sidewalkdirection;
	double	rotationangle;
	double	rotationspeed;
	double	fov_angle;
	double	num_rays;
	double	wall_strip_w;
	int		old_pos;

}	t_Player;

typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_rays
{
	double		*wallhitx;
	double		*wallhity;
	double		*distance;
	float		*rayangles;
	float		rayangle;
	double		h_xintercept;
	double		h_yintercept;
	double		v_xintercept;
	double		v_yintercept;
	double		xstep;
	double		ystep;
	bool		*israydown;
	bool		*israyup;
	bool		*israyright;
	bool		*israyleft;
	double		v_wallhitx;
	double		v_wallhity;
	double		h_wallhitx;
	double		h_wallhity;
	bool		*foundwall_h;
	bool		*foundwall_v;
	bool		*washit;
	long long	walltoppixel;
	long long	wallbottom_pixel;
	long long	wallstriphight;

}	t_rays;

typedef struct s_data
{
	t_img		*wall_text;
	t_img		main_img;
	t_Player	*player;
	t_rays		*rays;
	t_parse		*parse;
	void		*main_img_ptr;
	void		*img;
	void		*win;
	void		*mlx;
	void		*winx;
	char		**s;
	char		**cube;
	double		win_w;
	double		win_h;
	double		minimap_scale;
	float		x_check;
	float		y_check;
	long long	text_offx;
	long long	text_offy;
	int			hp;
	int			lp;
	int			xi;
	int			yi;
	int			mapi;
	int			mapj;
	int			*addr;
	int			up_right;
	int			up_left;
}	t_data;

void	draw_walls(t_data *d, int i);
double	normilize_angle(double angle);
void	cast_rays(t_data *ray);
void	init(t_data *img);
void	cast_horizontal_vertical_rays(t_data *dt, int i);
double	calculate_distance(double px, double py, double Ax, double Ay);
void	vertical_rays(t_data *dt, int i);
void	horizontal_rays(t_data *dt, int i);
void	ray_direction(t_data *dt, int i);
int		is_wall_at(double x, double y, t_data *map);
int		key_release(int keycode, t_data *img);
void	drawcircle(int x, int y, int color, t_data *img);
void	render_3d(t_data *img);
void	print_walls(int y, int x, t_data *d, char direction);
void	count_map(t_data *img);
void	load_wall(t_data *d);
int		rgba(unsigned int red, unsigned int green, unsigned int blue);
void	move_player(t_data *d);
int		move_position(int keycode, t_data *dt);
int		close_win(t_data *data);
int		mlx_data(t_data *img);
int		mouse(int x, int y, t_data *dt);
void	ft_free(t_data *dt);
void	free_char(char **str);

///////////////////////////////////////////////// parsing

//---------------------color_parse.c---------------------//
int		ft_atoi_color_f(char *str, t_parse *data);
int		ft_atoi_color_c(char *str, t_parse *data);
void	set_colors(char *str, t_parse *data);

//---------------------errors.c--------------------------//
int		display(char *error);
int		print_error_pos(int row, int column, char c);
void	error(t_parse *data, char *str);
int		ft_empty(char *str);

//---------------------map_parse_utils_1-----------------//
size_t	ft_arr_langth(char **map);
int		check_bottom_path(char **map, int i, int j);
int		ft_start(char c, t_parse *data, int i, int j);
size_t	ft_strspn(const char *str, char *charset);

//---------------------map_parse_utils.c-----------------//
int		check_map_content(char	**temp, char *charset);
int		check_valid_path(char **map, int i, int j);
int		check_for_error(char **map, int i, int j);

//---------------------map_parse.c-----------------------//
void	check_map(t_parse *data);
int		ft_parse_map(char *str, t_parse *data);
int		ft_strchr_map(char *str, int c);
int		valid_map(char *str, t_parse *data);
void	ft_is_map(char *str, t_parse *data);

//----------------------textures_parse.c-----------------//
char	*ft_texture_path(char *str, t_parse *data);
void	ft_parse_texture(char *str, t_parse *data);

//----------------------ft_split.c----------------------//
int		ft_cube(char *str, t_parse *data, t_data *img);
void	parser(char *file, t_parse *data, t_data *img);
t_parse	*init_data(void);

#endif