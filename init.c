/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:30 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 19:54:33 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/ft_printf.h"

//seteamos los valores minimo y maximo del valor real y imaginario a -2, 2
void	set_minmax(t_data *data)
{
	data->min_r = -2;
	data->max_r = data->min_r * -1 * LENGTH / HEIGHT;
	data->min_i = -2;
	data->max_i = data->min_i * -1 * HEIGHT / LENGTH;
	return ;
}

//se inicializan todos los valores a 0 o NULL
t_data	data_init(void)
{
	t_data	data;
	data.mlx = NULL;
	data.win = NULL;
	data.min_r = 0;
	data.max_r = 0;
	data.min_i = 0;
	data.max_i = 0;
	data.count = 0;
	data.color_shift = 1; // 1??
	data.resolution_shift = 0;
	data.set = 0;
	data.center_i = 0;
	data.center_r = 0;
	data.julia_shiftx = 0;
	data.julia_shifty = 0;
	data.args = NULL;
	data.img_data = simple_calloc(sizeof(t_img));
	data.color = simple_calloc(sizeof(t_color));
	return (data);
}

//inicializamos la mlx realizamos la generacion de la ventana
//creamos la instancia de la imagen
//recibimos los datos de la imagen con get data addr
void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		clean_exit(data);
		ft_putstr_fd("Error with initialization.\n", 1);
		return ;
	}
	win_generation(data);
	data->img_data->img = mlx_new_image(data->mlx, LENGTH, HEIGHT);
	if (!data->img_data->img)
	{
		clean_exit(data);
		ft_putstr_fd("Error image creation", 1);
		return ;
	}
	data->img_data->addr = mlx_get_data_addr(data->img_data->img, &data->img_data->bpp, \
			&data->img_data->line_len, &data->img_data->endian);
	return ;
}

//generamos la ventana dependiendo de si es mandelbrot o julia

void	win_generation(t_data *data)
{
	if (data->set == MANDELBROT)
	{
		data->win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "MANDELBROT");
		if (data->win == NULL)
		{
			clean_exit(data);
			ft_putstr_fd("Error initializing MANDELBROT", 1);
			exit(-1);
		}
	}
	if (data->set == JULIA)
	{
		data->win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "JULIA");
		if (data->win == NULL)
		{
			clean_exit(data);
			ft_putstr_fd("Error initializing JULIA", 1);
			exit(-1);
		}
	}
	return ;
}

//lista de comandos permitidos en nuestro programa
//
void	command_list(t_data *data)
{
	ft_putstr_fd("Available commands:\n", 1);
	ft_printf("WASD: move screen\n");
	ft_printf("Mouse Wheel: Zoom in / Zoom out\n");
	ft_printf("ESC: quits program\n");
	ft_printf("Left Shift: color shift\n");
	ft_printf("Left Alt: cycle through resolution (max iteration)\n");
	ft_printf("<!> +iterations = +resolution = -rendering speed <!>\n\n");
	if (data->set == JULIA)
	{
		ft_printf("For Julia sets:\nDefault parameters = %d, %d (image \
				center)\n", HEIGHT / 2, LENGTH / 2);
	}
	return ;
}
