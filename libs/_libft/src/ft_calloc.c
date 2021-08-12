/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:38:22 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/06 12:40:33 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	if (size <= 0)
		return (NULL);
	i = -1;
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	while (++i < (size * nmemb))
		p[i] = '\0';
	return (p);
}
