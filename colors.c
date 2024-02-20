/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:13:58 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 18:23:12 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_color(t_data *data)
{
	data->color_shift += 1;
	if (data->color_shift > 5)
		data->color_shift = 1;
	return ;
}

//si se desea cambiar los colores, esta es la funcion
void	apply_shift(t_data *data)
{
	if (data->color_shift == 1)
	{
		data->color->r += 150;
		data->color->b += 10;
	}
	else if (data->color_shift == 2)
	{
		data->color->r += 70;
		data->color->b += 70;
	}
	else if (data->color_shift == 3)
		data->color->g += 75;
	else if (data->color_shift == 4)
		data->color->b += 140;
	else
	{
		data->color->b = 75;
		data->color->g += 75;
	}
	return ;
}

int	get_red(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (255);
	else if (color_value > 255 && color_value <= 510)
		return (255 - (color_value - 255));
	else if (color_value > 510 && color_value <= 1020)
		return (0);
	else if (color_value > 1020 && color_value <= 1275)
		return (color_value - 1020);
	else
		return (255);
}

int	get_green(int color_value)
{
	if (color_value >= 0 && color_value <= 255)
		return (color_value);
	else if (color_value > 255 && color_value <= 765)
		return (255);
	else if (color_value > 765 && color_value <= 1020)
		return (255 - (color_value - 765));
	else if (color_value > 1020 && color_value <= 1275)
		return (0);
	else
		return (255);
}

int	get_blue(int color_value)
{
	if (color_value >= 0 && color_value <= 510)
		return (0);
	if (color_value > 510 && color_value <= 765)
		return (color_value - 510);
	else
		return (255);
}
