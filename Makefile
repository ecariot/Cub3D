# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:09:10 by emcariot          #+#    #+#              #
#    Updated: 2022/07/01 14:13:22 by emcariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=

OBJS		= ${SRCS:.c=.o}

NAME		= cub3d

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3

RM			= @rm -f

%.o: %.c
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -Iincludes -Ilibft -c $< -o ${<:.c=.o}

${LIBFT}:
			@echo "\033[35m----Building libft----"
			@make -sC ${LIB_DIR}
			@echo "OK"

${NAME}:	${OBJS} ${LIBFT}
			@echo "\033[34m----Compiling----"
			@${CC} ${FLAGS} ${OBJS} -lreadline -o ${NAME} ${LIBFT}
			@echo "OK"

clean:
			@echo "\033[31m----Cleaning libft----"
			@make clean -sC ${LIB_DIR}
			@echo "OK"
			@echo "\033[31m----Cleaning objects----"
			@${RM} ${OBJS}
			@echo "OK"

fclean:		clean
			@echo "\033[33m----Cleaning all----"
			@${RM} ${NAME}
			@${RM} ${LIBFT}
			@echo "OK"

re:			fclean all

.PHONY:		all clean fclean re
