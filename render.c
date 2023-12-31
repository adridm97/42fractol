/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:09:06 by aduenas-          #+#    #+#             */
/*   Updated: 2023/11/08 22:58:13 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(t_data *data, char *argv)
{
	argv = ft_str_tolower(argv);
	if (ft_strcmp(argv, "mandelbrot") == 0)
		data->set = MANDELBROT;
	else if (ft_strcmp(argv, "julia") == 0)
		data->set = JULIA;
	else
	{
		write(1, "Error", 5);
		clean_exit(data);
	}
	return ;
}

int	generate_fractal(t_data *data)
{
	handle_events(data);
}
