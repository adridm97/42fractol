/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:23:28 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 23:23:34 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(double cr, double ci, t_data *data)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i <= MAX_ITERATION + data->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			data->count = i;
			return (0);
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
			data->count = i;
	return (1);
}

void	generate_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		pi = data->max_i + ((double)y * (data->min_i - data->max_i) / HEIGHT);
		x = -1;
		while (++x < LENGTH)
		{
			pr = data->min_r + ((double)x * (data->max_r - data->min_r) / LENGTH);
			if (is_mandelbrot(pr, pi, data) == 0)
				my_px_put(data->img_data, x, y, make_color(data));
			else
				my_px_put(data->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
	return ;
}
