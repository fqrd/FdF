/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdiuXx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:28:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/06 16:35:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_char(va_list args, size_t **count)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	**count += ft_putchar(c);
}

void	ft_string(va_list args, size_t **count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	**count += ft_putstr(str);
}

void	ft_decimal(va_list args, size_t **count)
{
	int	nbr;

	nbr = va_arg(args, int);
	**count += print_num((long long)nbr, 0);
}

void	ft_unsigned_decimal(va_list args, size_t **count)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	(**count) += print_num((long long)nbr, 0);
}

void	ft_hexadecimal_number(va_list args, size_t **count, char format)
{
	unsigned int	x;
	char			*base_x;
	char			*base_X;

	base_x = "0123456789abcdef";
	base_X = "0123456789ABCDEF";
	x = va_arg(args, unsigned int);
	if (format == 'x')
		**count += to_hex_long((unsigned long long)x, base_x, 0);
	else
		**count += to_hex_long((unsigned long long)x, base_X, 0);
}
