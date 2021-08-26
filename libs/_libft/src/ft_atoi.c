/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:32:29 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/04 19:03:04 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static long long	prevent_overflow(char c, long long *nbr)
{
	long long	add;

	add = 10 * *nbr + (c - '0');
	if (add > *nbr && ((add / 100) < (*nbr / 10)))
		add *= (-1);
	if (add > *nbr && ((add / 100) >= (*nbr / 10)))
		*nbr = add;
	return (add);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	long long	add;
	int			sign;

	nbr = 0;
	sign = 1;
	add = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str && *str >= 48 && *str <= 57)
	{
		add = prevent_overflow(*str, &nbr);
		str++;
	}
	if ((add < nbr && sign == 1))
		return (-1);
	if (add < nbr && sign == -1)
		return (0);
	return ((int)(nbr * sign));
}
