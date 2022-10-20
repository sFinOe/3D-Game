# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 15:39:39 by sayar             #+#    #+#              #
#    Updated: 2022/10/20 21:20:31 by zkasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

NAME_B = Cub3d_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC =	map_parsing/colors_parse.c\
		map_parsing/parser.c\
		map_parsing/parsing_errors.c\
		map_parsing/map_parse_utils_1.c\
		map_parsing/map_parse_utils.c\
		map_parsing/map_parse.c\
		map_parsing/textures_parse.c\
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

SRC_B =	bonus/errors.c\
		bonus/horizontal.c\
		bonus/init.c\
		bonus/main.c\
		bonus/mini_map.c\
		bonus/mini_map_utils.c\
		bonus/mouse.c\
		bonus/movements.c\
		bonus/rays.c\
		bonus/render3d.c\
		bonus/textures.c\
		bonus/vertical.c\
		map_parsing/colors_parse.c\
		map_parsing/parser.c\
		map_parsing/parsing_errors.c\
		map_parsing/map_parse_utils_1.c\
		map_parsing/map_parse_utils.c\
		map_parsing/map_parse.c\
		map_parsing/textures_parse.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

PREFIX = ./obj/

OBJ = $(addprefix $(PREFIX), $(SRC:.c=.o))

OBJ_B = $(addprefix $(PREFIX), $(SRC_B:.c=.o))

all : ${NAME}

.PHONY : all clean fclean re

libft/libft.a:
	make -C libft

$(PREFIX) :
	@mkdir -p $(PREFIX)
	@mkdir -p $(PREFIX)/mandatory
	@mkdir -p $(PREFIX)/map_parsing
	@mkdir -p $(PREFIX)/gnl
	@mkdir -p $(PREFIX)/bonus

${NAME} : libft/libft.a mandatory/cub3d.h gnl/get_next_line.h $(PREFIX) ${OBJ}
	${CC} ${FLAGS} ${OBJ} libft/libft.a -lmlx -framework OpenGL -framework AppKit -g -o ${NAME}

bonus : ${NAME} libft/libft.a bonus/cub3d_bonus.h gnl/get_next_line.h $(PREFIX) ${OBJ_B}
	${CC} ${FLAGS} ${OBJ_B} libft/libft.a -lmlx -framework OpenGL -framework AppKit -g -o ${NAME_B}

$(PREFIX)%.o: %.c mandatory/cub3d.h bonus/cub3d_bonus.h
	$(CC) ${FLAGS} -g -c -o $@ $<

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
