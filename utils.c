/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:39:57 by aduenas-          #+#    #+#             */
/*   Updated: 2023/11/08 23:50:32 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
char	*ft_str_tolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	*simple_calloc(size_t size)
{
	void	*str;

	str = (void *)malloc (size);
	if (str == NULL)
	{
		write(1, "calloc error", 12);
		exit (-1);
	}
	ft_bzero(str, (size));
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	clean_exit(t_data *f)
{
	if (f->img_data->img)
	{
		mlx_destroy_image(f->mlx, f->img_data->img);
		free(f->img_data);
	}
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->color)
		free(f->color);
	ft_putstr_fd("Exit", 1);
	exit(0);
}
