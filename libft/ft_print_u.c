/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:04:46 by aduenas-          #+#    #+#             */
/*   Updated: 2023/08/25 21:35:28 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len -1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_itoa_u(n);
		if (!num)
			return (-1);
		length += ft_printstr(num);
		free(num);
	}
	return (length);
}
