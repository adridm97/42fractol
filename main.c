/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:22 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/28 16:47:01 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_data	data;
	
	if (argc < 2 || !argv[1])
	{
		write(1, "error, missing argument", 23);
		return (-1);
	}
	data = data_init();
	set_minmax(&data);
	data.args = argv;
	check_args(&data, argv[1]);
	return (0);
}
