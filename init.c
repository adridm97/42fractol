/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:30 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/28 16:08:34 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_minmax(t_data *data)
{
	data->min_r = -2;
	data->max_r = data->min_r * -1 * WIDTH / HEIGHT;
	data->min_i = -2;
	data->max_i = data->min_i * -1 * WIDTH / LENGTH;
	return ;
}

t_data	data_init()
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
	data.img_data = x_calloc(sizeof(t_img));
	data.color = x_calloc(sizeof(t_color));
	return (data);
}
