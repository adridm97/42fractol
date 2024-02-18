/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:36:37 by aduenas-          #+#    #+#             */
/*   Updated: 2023/08/25 21:44:04 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_type(va_list args, const char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (type == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		length += ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (type == 'u')
		length += ft_printunsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		length += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_process_string(const char *str, va_list args)
{
	int	i;
	int	length;
	int	tmp;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = ft_type(args, str[++i]);
			if (tmp == -1)
				return (-1);
			length += tmp;
		}
		else
		{
			tmp = ft_printchar(str[i]);
			if (tmp == -1)
				return (-1);
			length += tmp;
		}
		i++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	va_start(args, str);
	length = ft_process_string(str, args);
	va_end(args);
	return (length);
}
/*
int	main(void)
{
	char	*str;
	char	chr;
	int	i;
	int	num;
	int *ptr;

	num = 1230456798;
	str = "Hola Mundo";
	chr = 'c';
	ptr = &num;

	ft_printf("El valor de ptr apuntando a num es: %d \n", *ptr);
	i = ft_printf("ft_printf: the string is: %s\n", str);
	ft_printf("ft_printf: the number is: %i \n", i);
	ft_printf("ft_printf: the char to be printed is: %c\n", chr);
	ft_printf("ft_printf: the number to be printed is: %i\n",num);
	ft_printf("ft_printf: %u \n", -10);
	ft_printf("ft_printf: %x \n", 16);

	ft_printf("%% \n");

	i = printf("printf: the string is: %s\n", str);
	printf("printf: the number is: %i \n", i);
	printf("printf: the char to be printed is: %c\n", chr);
	printf("printf: the number to be printed is: %i\n",num);
	printf("printf: %u \n", -10);
	printf("printf: %x \n", 16);
	return (0);
}
*/
