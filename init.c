/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:30 by aduenas-          #+#    #+#             */
/*   Updated: 2023/11/08 22:02:42 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_minmax(t_data *data)
{
	data->min_r = -2;
	data->max_r = data->min_r * -1 * LENGTH / HEIGTH;
	data->min_i = -2;
	data->max_i = data->min_i * -1 * HEIGTH / LENGTH;
	return ;
}

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
	data.color_shift = 1; // 0??
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
	data->img_data->img = mlx_new_image(data->mlx, LENGTH, HEIGTH);
	if (!data->img_data->img)
	{
		clean_exit(data);
		ft_putstr_fd("Error image creation", 1);
		return ;
	}

//	mlx_loop(data->mlx);
//	free(data->mlx);
}

void	win_generation(t_data *data)
{
	if (data->set == MANDELBROT)
	{
		data->win = mlx_new_window(data->mlx, LENGTH, HEIGTH, "MANDELBROT");
		if (data->win == NULL)
		{
			clean_exit(data);
			ft_putstr_fd("Error initializing MANDELBROT", 1);
			exit(-1);
		}
	}
	if (data->set == JULIA)
	{
		data->win = mlx_new_window(data->mlx, LENGTH, HEIGTH, "JULIA");
		if (data->win == NULL)
		{
			clean_exit(data);
			ft_putstr_fd("Error initializing JULIA", 1);
			exit(-1);
		}
	}
	return ;
}
