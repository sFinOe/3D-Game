# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 11:11:14 by zkasmi            #+#    #+#              #
#    Updated: 2022/10/26 13:05:21 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isdigit.c\
ft_memcpy.c\
ft_split.c\
ft_strlen.c\
ft_substr.c\
ft_atoi.c\
ft_isprint.c\
ft_memmove.c\
ft_strchr.c\
ft_strmapi.c\
ft_tolower.c\
ft_bzero.c\
ft_itoa.c\
ft_memset.c\
ft_strdup.c\
ft_strncmp.c\
ft_toupper.c\
ft_calloc.c\
ft_putchar_fd.c\
ft_striteri.c\
ft_isalnum.c\
ft_putendl_fd.c\
ft_strjoin.c\
ft_strnstr.c\
ft_isalpha.c\
ft_memchr.c\
ft_putnbr_fd.c\
ft_strlcat.c\
ft_strrchr.c\
ft_isascii.c\
ft_memcmp.c\
ft_putstr_fd.c\
ft_strlcpy.c\
ft_strtrim.c\
ft_strcmp.c\
ft_strcspn.c\
ft_strspn.c\

SRC2 = ft_lstclear.c\
ft_lstadd_back.c\
ft_lstnew.c\
ft_lstsize.c\
ft_lstadd_front.c\
ft_lstdelone.c\
ft_lstlast.c\
ft_lstiter.c\

OBJS = ${SRC:.c=.o}

OBJS2 = ${SRC2:.c=.o}

all: $(NAME)

%.o: %.c libft.h
			${CC} -c ${CFLAGS} -o $@ $<

$(NAME): ${OBJS}
		@ar -rc ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS2}
		@ar -rc ${NAME} ${OBJS} ${OBJS2}

.PHONY: all clean fclean bonus

clean:
	@rm -f ${OBJS} ${OBJS2}

fclean: clean
	@rm -f ${NAME}

re: fclean all