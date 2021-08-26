/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:34:59 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/05 17:04:41 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	size_src;

	if (!dest && !src)
		return (0);
	index = 0;
	size_src = ft_strlen(src);
	if (size_src < size)
		size = size_src + 1;
	while (index < size)
	{
		if (index + 1 == size)
			dest[index] = '\0';
		else
			dest[index] = src[index];
		index++;
	}
	return (size_src);
}
