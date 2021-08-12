/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:01:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/04 19:12:21 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr(long long nb)
{
	if (nb < 10 && nb > -10)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= (-1);
		}
		ft_putchar((char) nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		if (nb < 0)
			ft_putchar((char)(((nb % 10) * (-1)) + '0'));
		else
			ft_putchar((char)((nb % 10) + '0'));
	}
}
