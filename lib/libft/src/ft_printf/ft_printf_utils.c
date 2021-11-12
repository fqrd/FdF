/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:26:40 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/12 14:07:24 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_num(long long nb, int n)
{
	if (nb < 10 && nb > -10)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= (-1);
			n++;
		}
		ft_putchar((char) nb + '0');
		n++;
	}
	else
	{
		n = print_num(nb / 10, n);
		if (nb < 0)
			ft_putchar((char)(((nb % 10) * (-1)) + '0'));
		else
			ft_putchar((char)((nb % 10) + '0'));
		n++;
	}
	return (n);
}

int	to_hex_long(unsigned long long x, char *base, int n)
{
	if (x < 16)
	{
		ft_putchar(base[x]);
		n++;
	}
	else
	{
		n = to_hex_long(x / 16, base, n);
		ft_putchar(base[x % 16]);
		n++;
	}
	return (n);
}
