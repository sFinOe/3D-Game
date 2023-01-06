# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 15:39:39 by sayar             #+#    #+#              #
#    Updated: 2022/10/26 16:25:07 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

NAME_B = Cub3d_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC =	map_parsing/array_func.c\
		map_parsing/check_map_elem.c\
		map_parsing/export_utils.c\
		map_parsing/ft_get_map.c\
		map_parsing/check_map.c\
		map_parsing/error.c\
		map_parsing/ft_export.c\
		map_parsing/parse.c\
		map_parsing/parse_colors.c\
		mandatory/errors.c\
		mandatory/horizontal.c\
		mandatory/init.c\
		mandatory/main.c\
		mandatory/movements.c\
		mandatory/rays.c\
		mandatory/render3d.c\
		mandatory/textures.c\
		mandatory/vertical.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

SRC_B =	bonus/errors_bonus.c\
		bonus/horizontal_bonus.c\
		bonus/init_bonus.c\
		bonus/main_bonus.c\
		bonus/mini_map_bonus.c\
		bonus/mini_map_utils_bonus.c\
		bonus/mouse_bonus.c\
		bonus/movements_bonus.c\
		bonus/rays_bonus.c\
		bonus/render3d_bonus.c\
		bonus/textures_bonus.c\
		bonus/vertical_bonus.c\
		map_parsing/array_func.c\
		map_parsing/check_map_elem.c\
		map_parsing/export_utils.c\
		map_parsing/ft_get_map.c\
		map_parsing/check_map.c\
		map_parsing/error.c\
		map_parsing/ft_export.c\
		map_parsing/parse.c\
		map_parsing/parse_colors.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

PREFIX = ./obj/

OBJ = $(addprefix $(PREFIX), $(SRC:.c=.o))

OBJ_B = $(addprefix $(PREFIX), $(SRC_B:.c=.o))

all : ${NAME}

.PHONY : all clean fclean re

libft/libft.a:
	make bonus -C libft

$(PREFIX) :
	@mkdir -p $(PREFIX)
	@mkdir -p $(PREFIX)/mandatory
	@mkdir -p $(PREFIX)/map_parsing
	@mkdir -p $(PREFIX)/gnl
	@mkdir -p $(PREFIX)/bonus

${NAME} : libft/libft.a mandatory/cub3d.h $(PREFIX) ${OBJ}
	${CC} ${FLAGS} ${OBJ} libft/libft.a -lmlx -framework OpenGL -framework AppKit  -o ${NAME}

bonus : ${NAME} libft/libft.a bonus/cub3d_bonus.h $(PREFIX) ${OBJ_B}
	${CC} ${FLAGS} ${OBJ_B} libft/libft.a -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}

$(PREFIX)%.o: %.c mandatory/cub3d.h bonus/cub3d_bonus.h
	$(CC) ${FLAGS} -c -o $@ $<

clean :
	rm -rf ${OBJ}
	rm -rf ${OBJ_B}
	@rm -rf ${PREFIX}
	make -C libft clean

fclean : clean
	rm -rf ${NAME}
	rm -rf ${NAME_B}
	make -C libft fclean

re : fclean all
