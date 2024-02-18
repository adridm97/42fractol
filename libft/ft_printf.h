/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:12:59 by aduenas-          #+#    #+#             */
/*   Updated: 2024/02/05 19:57:39 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_process_string(const char *str, va_list args);
int		ft_printf(const char *str, ...);
int		ft_type(va_list args, const char type);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_hexlen(unsigned int n);
int		ft_printhex(unsigned int n, const char type);
int		ft_printpercent(void);
int		ft_printunsigned(unsigned int n);
int		ft_length(unsigned int n);
int		ft_puthex(unsigned int n, const char type);

char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
#endif
