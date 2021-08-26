/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:59:57 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/06 16:35:11 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	ft_hexadecimal_pointer(va_list args, size_t **count)
{
	unsigned long long	p;
	char				*base;

	base = "0123456789abcdef";
	p = (unsigned long long)va_arg(args, void *);
	if (!p)
		**count += ft_putstr("0x0");
	else
	{
		**count += ft_putstr("0x");
		**count += to_hex_long(p, base, 0);
	}
}

static void	function_switch(char format, va_list args, size_t *count)
{
	if (format == '%')
		*count += ft_putchar('%');
	if (format == 'c')
		ft_char(args, &count);
	if (format == 's')
		ft_string(args, &count);
	if (format == 'd' || format == 'i')
		ft_decimal(args, &count);
	if (format == 'u')
		ft_unsigned_decimal(args, &count);
	if (format == 'x' || format == 'X')
		ft_hexadecimal_number(args, &count, format);
	if (format == 'p')
		ft_hexadecimal_pointer(args, &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			write (1, &*format++, 1);
			count++;
		}
		if (*format && *(++format))
		{
			function_switch(*format++, args, &count);
		}
	}
	va_end(args);
	return (count);
}
