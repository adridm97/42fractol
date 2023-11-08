/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:31:12 by aduenas-          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:15 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"

# define MANDELBROT 1
# define JULIA 2
# define LENGTH 600
# define HEIGTH 600

enum {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	LEFT_CTRL = 256,
	LEFT_ALT = 261,
	LEFT_SHIFT = 257,
	ESC			= 53,
	ON_DESTROY	= 17,
	ON_MOUSE_DW	= 4,
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			*img_data;
	t_color			*color;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	unsigned int	count;
	int				color_shift;
	int				resolution_shift;
	int				set;
	double			center_i;
	double			center_r;
	double			julia_shiftx;
	double			julia_shifty;
	char			**args;
}	t_data;

void	check_fractal(t_data *data, char *argv);
void	set_minmax(t_data *data);
t_data	data_init(void);
char	*ft_str_tolower(char *str);
void	*simple_calloc(size_t size);
int		ft_strcmp(const char *s1, const char *s2);
void	clean_exit(t_data *f);
void	mlx_setup(t_data *data);
void	win_generation(t_data *data);
int		generate_fractal(t_data *data);

#endif
