/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:08 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 18:08:58 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	choose(char deli, va_list params)
{
	if (deli == 'x' || deli == 'X')
		return (hex_convert(deli, va_arg(params, unsigned int)));
	else if (deli == 'c')
	{
		(ft_putchar_fd(va_arg(params, int), 1));
		return (1);
	}
	else if (deli == '%')
		return (write(1, "%", 1));
	else if (deli == 'p')
		return (point_conv((unsigned long)va_arg(params, void *)));
	else if (deli == 'd' || deli == 'i')
		return (print_num(va_arg(params, int), 1));
	else if (deli == 'u')
		return (print_unum(va_arg(params, unsigned int), 1));
	else if (deli == 's')
		return (print_str(va_arg(params, char *), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		result;

	if (!format)
		return (-1);
	result = 0;
	va_start(params, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			result++;
			ft_putchar_fd(*format, 1);
		}
		else
		{
			format++;
			result += choose(*format, params);
		}
		format++;
	}
	va_end(params);
	return (result);
}
