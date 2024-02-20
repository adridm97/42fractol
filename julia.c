/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:27:41 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 17:26:57 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/ft_printf.h"

void	generate_julia(t_data *data)
{
  int		x;
	int		y;
	double	pr;
	double	pi;

	if (!data)
		return ;
	y = -1;
	while (++y < HEIGHT)
	{
		pi = data->max_i + ((double)y * (data->min_i - data->max_i) / HEIGHT);
		x = -1;
		while (++x < LENGTH)
		{
			pr = data->min_r + ((double)x * (data->max_r - data->min_r) / LENGTH);
			if (is_julia(pr, pi, data) == 0)
				my_px_put(data->img_data, x, y, make_color(data));
			else
				my_px_put(data->img_data, x, y, create_trgb(0, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
	return ;
}

int	is_julia(double zr, double zi, t_data	*data)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < MAX_ITERATION + data->resolution_shift)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			data->count = i;
			return (0);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + data->julia_shifty;
		zr = tmp + data->julia_shiftx;
	}
		data->count = i;
	return (1);
}

void	julia_shift(int x, int y, t_data *data)
{
	data->julia_shiftx = data->min_r + (double)x * (data->max_r - data->min_i) / LENGTH;
	data->julia_shifty = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	ft_printf("New Julia Parameters: x = %d, y = %d\n", x, y);
	return ;
}
