/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:22:48 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 19:34:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	rec_hex(char *str, size_t i, int d, size_t len)
{
	char	*base;

	base = "0123456789abcdef";
	if (i == len)
		return (ft_charpos(base, ft_tolower(str[i])));
	else
	{
		d = rec_hex(str, ++i, d, len);
		d += (ft_power(16, (len - i)) * ft_charpos(base, ft_tolower(str[i])));
		return (d);
	}
	return (d);
}

int	ft_atoi_hex(char *str)
{
	int		d;
	char	*trimmed;

	trimmed = ft_strtrim(str, " \t\n\v\f\r");
	if (str[0] == '0' && str[1] == 'x')
		str = ft_substr(trimmed, 1, ft_strlen(trimmed) - 2);
	else
		str = trimmed;
	free (trimmed);
	d = rec_hex(str, 0, 0, ft_strlen(str));
	free(str);
	return (d);
}
