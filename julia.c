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
	double	r;
	double	i;

	if (!data)
		return ;
	y = 0;
	while(++y < HEIGHT)
	{
		i = data->max_i + ((double)y * (data->min_i - data->max_i) / HEIGHT);
		x = 0;
		while(x < LENGTH)
		{
			r = data->min_r + ((double)x * (data->max_r - data->min_r) / LENGTH);
			if(is_julia(r, i, data) == 0)
				my_px_put(data->img_data, x, y, make_color(data);
			x++;
		}
		y++;
	}
}

int	is_julia(double r, double i, t_data *data)
{
	double	tmp;
	int		x;

	x = 1;
	while (x < MAX_ITERATION + data->resolution_shift)
	{
		if((r * r + i * i) > 4)
		{
			data->count = x;
			return (0);
		}
		tmp = r * r - i * i;
		i = 2 * r * i + data->julia_shifty;
		r = tmp + data->julia_shiftx;
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
