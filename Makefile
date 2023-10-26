# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 21:31:28 by aduenas-          #+#    #+#              #
#    Updated: 2023/10/26 22:58:40 by aduenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRC = main.c

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# en -Lmlx substituir mlx por el path a la carpeta, por ejemplo: libs/minilibs seria -Llibs/minilibs

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft/
	${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME} libft/libft.a

clean:
	${MAKE} -C libft/ clean
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME} ${OBJS}
	${MAKE} -C libft/ fclean

re: fclean all

.PHONY: re clean fclean all
