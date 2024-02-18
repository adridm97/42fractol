/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:58:53 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/18 20:21:12 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//desde aqui manejamos los eventos del raton
int	handle_mouse(int code, int x, int y, t_data *data)
{
	(void)x;
	(void)y;

	if (code == 4)
		mouse_zoom(data, 0.9, x, y);
	if (code == 5)
		mouse_zoom(data, 1.1, x, y);
	if (code == 2 && data->set == JULIA)
		julia_shift(x, y, data);
	return (0);
}

//registra todos los eventos de inputs y los maneja con las funciones de la mlx
int	handle_events(t_data *data)
{
	mlx_hook(data->win, ON_MOUSE_DW, 0, handle_mouse, data);
	mlx_key_hook(data->win, handle_keys, data);
	mlx_hook(data->win, ON_DESTROY, 0, (void *)clean_exit, data);
	return (0);
}

//recibe los imputs del usuario y envia los datos a la funcion move
//para que los realize
int	handle_keys(int keycode, t_data *data)
{
	if (keycode == ESC)
		clean_exit(data);
	if (keycode == LEFT_SHIFT)
		shift_color(data);
	if (keycode == W || keycode == UP_ARROW)
		move(data, 'U');
	if (keycode == S || keycode == DOWN_ARROW)
		move(data, 'D');
	if (keycode == A || keycode == LEFT_ARROW)
		move(data, 'L');
	if (keycode == D || keycode == RIGHT_ARROW)
		move(data, 'R');
	if (keycode == LEFT_ALT)
	{
		data->resolution_shift += 50;
		if (data->resolution_shift > 200)
			data->resolution_shift = 0;
		ft_printf("Max iterations: %d\n", (data->resolution_shift + MAX_ITERATION));
	}
	return (0);
}
