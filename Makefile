# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 21:31:28 by aduenas-          #+#    #+#              #
#    Updated: 2023/11/08 23:48:18 by aduenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
HEADER = fractol.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fractol
SRC = main.c render.c utils.c init.c events.c

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# en -Lmlx substituir mlx por el path a la carpeta, por ejemplo: libs/minilibs seria -Llibs/minilibs

all: libft ${NAME}

libft:
	${MAKE} -C ./libft

${NAME}: ${OBJS} ${LIBFT} ${HEADER}
	${CC} ${CFLAGS} ${MLX} ${LIBFT} ${OBJS} -o ${NAME} 

clean:
	${MAKE} -C ./libft clean
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME} ${OBJS}
	${MAKE} -C ./libft fclean

re: fclean all

.PHONY: re clean fclean all libft
