# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 21:31:28 by aduenas-          #+#    #+#              #
#    Updated: 2024/02/18 23:21:58 by aduenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fractol
HEADER = fractol.h
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


SRC = main.c render.c utils.c init.c events.c \
	  julia.c colors.c fractol_utils.c mandelbrot.c

OBJS = ${SRC:.c=.o}

%.o: %.c $(LIBFT) Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# en -Lmlx substituir mlx por el path a la carpeta, \
	 por ejemplo: libs/minilibs seria -Llibs/minilibs

all: libft mlx ${NAME} Makefile

mlx: 
	$(MAKE) -C ./mlx

libft:
	${MAKE} -C ./libft

${NAME}: ${OBJS} ${LIBFT} ${HEADER} $(MLX)
	${CC} ${CFLAGS} ${MLX_FLAGS} ${LIBFT} ${OBJS} -o $@ 

clean:
	${MAKE} -C ./libft clean
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	${MAKE} -C ./libft fclean
	${MAKE} -C ./mlx clean

re: fclean all

.PHONY: re clean fclean all libft mlx
