/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:22 by aduenas-          #+#    #+#             */
/*   Updated: 2023/10/26 23:46:08 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  create_window(t_list *program)
{
  program->ptr = mlx_init();
  program->win = mlx_new_window(program->ptr, 1080, 600, "fract-ol");
}

int main(int argc, char **argv)
{
  t_list program;

  if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		  || argc == 4 && !ft_strncmp(argv[1], "julia", 5))
  {
	  create_window(&program);
	  mlx_loop(program.ptr);
  }
  return (0);
}
