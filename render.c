/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:09:06 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/20 19:24:08 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/ft_printf.h"

//Chequea los argv y inicializa data->set si el argumento es correcto
//sino da error y se cierra el programa

void	check_fractal(t_data *data, char *argv)
{
	argv = ft_str_tolower(argv);
	if (ft_strcmp(argv, "mandelbrot") == 0)
		data->set = MANDELBROT;
	else if (ft_strcmp(argv, "julia") == 0)
		data->set = JULIA;
	else
	{
		ft_printf("Error: no such fractal\n");
		ft_printf("Available fractals: Mandelbrot, Julia\n");
		clean_exit(data);
	}
	return ;
}

//comprueba que hay en data->set y inicializa el fractal correspondiente
int	generate_fractal(t_data *data)
{
	handle_events(data);
	if (data->set == JULIA)
		generate_julia(data);
	if (data->set == MANDELBROT)
		generate_mandelbrot(data);
	return (0);
}

//a traves de bit shifting definimos los colores
// TTT RRR GGG BBB
// transparente, rojo, verde, azul

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color(t_data *data)
{
	int	color_value;

	color_value = data->count * 15;
	data->color->r = get_red(color_value);
	data->color->g = get_green(color_value);
	data->color->b = get_blue(color_value);
	apply_shift(data);
	return (create_trgb(0, data->color->r, data->color->g, \
			data->color->b));
}
