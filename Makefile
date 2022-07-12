
SRCS		=	parsing/parse_map.c game/init_game.c \
				toolbox/error.c toolbox/utils.c main.c\
				parsing/parse_texture.c  game/moves.c\
				parsing/init.c parsing/check_map.c parsing/check_texture.c\
				parsing/global_parsing.c game/raycast.c \

OBJS        = ${SRCS:.c=.o}

NAME        = cub3d

INCL        = includes

LIB_DIR = ./libft
MLX_DIR = ./mlx_linux

LIBFT	= ./libft/libft.a
MLX = ./mlx_linux/libmlx.a

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -g3
FLAGS_LIB = -lXext -lX11

all:		${NAME}

.c.o:
			${CC} ${FLAGS} -I${INCL} -c $< -o ${<:.c=.o}

${LIBFT}:
			@echo "\033[35m----Building libft----"
			@make -sC ${LIB_DIR}
			@echo "OK"

${MLX}:
			@echo "\033[35m----Building MLX----"
			@make -sC ${MLX_DIR}
			@echo "OK"

${NAME}:	${OBJS} ${LIBFT} ${MLX}
			@echo "\033[34m----Compiling----"
			@${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME} ${LIBFT}
			@echo "OK"

clean:
			@echo "\033[31m----Cleaning libft----"
			@make clean -sC ${LIB_DIR}
			@echo "OK"
			@echo "\033[31m----Cleaning MLX----"
			@make clean -sC ${MLX_DIR}
			@echo "OK"
			@echo "\033[31m----Cleaning objects----"
			@${RM} ${OBJS}
			@echo "OK"

fclean:		clean
			@echo "\033[33m----Cleaning all----"
			@${RM} ${NAME}
			@${RM} ${LIBFT}
			@${RM} ${MLX}
			@echo "OK"

re:            fclean all

.PHONY:        all clean fclean re
