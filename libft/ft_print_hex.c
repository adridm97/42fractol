/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:09:14 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/05 19:58:22 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_put_hexdigit(unsigned int n, const char type)
{
	if (n <= 9)
		return (ft_printchar(n + '0'));
	else
	{
		if (type == 'x')
			return (ft_printchar(n - 10 + 'a'));
		else if (type == 'X')
			return (ft_printchar(n - 10 + 'A'));
	}
	return (-1);
}

int	ft_puthex(unsigned int n, const char type)
{
	if (n >= 16)
	{
		if (ft_puthex(n / 16, type) == -1)
			return (-1);
	}
	return (ft_put_hexdigit(n % 16, type));
}

int	ft_printhex(unsigned int n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		if (ft_puthex(n, type) == -1)
			return (-1);
	return (ft_hexlen(n));
}
