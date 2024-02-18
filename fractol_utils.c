/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:59:59 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 20:13:43 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//esta funcion sirve para mover la imagen acorde con la tecla presionada
//el 0.1 es un valor ajustable, contra mas grande sea,
// mayor incremento de movimiento.
void	move(t_data	*data, char direction)
{
	data->center_r = data->min_r - data->max_r;
	data->center_i = data->min_i - data->max_i;
	if (direction == 'U')
	{
		data->min_i -= data->center_i * 0.1;
		data->max_i -= data->center_i * 0.1;
	}
	if (direction == 'D')
	{
		data->min_i += data->center_i * 0.1;
		data->max_i += data->center_i * 0.1;
	}
	if (direction == 'R')
	{
		data->min_r -= data->center_r * 0.1;
		data->max_r -= data->center_r * 0.1;
	}
	if (direction == 'L')
	{
		data->min_r += data->center_r * 0.1;
		data->max_r += data->center_r * 0.1;
	}
	return ;
}

//utilizando la direccion de memoria de la imagen almacenada
//en img->addr buscamos la direccion de memoria del px a cambiar el color
// y se aplica el color deseado
void	my_px_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	ft_is_little_endian(void)
{
	int	n;

	n = 1;
	if (*(char *)&n == 1)
		return (1);
	else
		return (0);
}
