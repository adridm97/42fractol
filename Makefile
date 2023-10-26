
CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRC = main.c

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

MLX = -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME}

re: fclean all

.PHONY: re clean fclean all
