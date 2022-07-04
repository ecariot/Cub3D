# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:09:10 by emcariot          #+#    #+#              #
#    Updated: 2022/07/04 14:44:22 by emcariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	parsing/parse_map.c game/init_game.c \
				toolbox/error.c main.c\

OBJS		= ${SRCS:.c=.o}

NAME		= cub3d

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3

RM			= rm -f

MLX			= ./mlx_linux

MLX_LIB		= ./mlx_linux/libmlx_Linux.a

INCL		= includes

.c.o:
			${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${MLX_LIB}
			${CC}  ${CFLAGS} ${OBJS} -o ${NAME} ${MLX_LIB}\
			-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${MLX_LIB}:
			make -C ${MLX} -j

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${MLX}

fclean:			clean
			${RM} ${NAME}
			${RM} ${NAME} ${MLX_LIB}

re:			fclean all

.PHONY:		all clean fclean re
