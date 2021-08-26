/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:30:37 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/05 17:03:22 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ps;
	char			*substring;
	size_t			llock;

	llock = 0;
	ps = (char *) s;
	if (!s || len == 0 || start > ft_strlen(s))
	{
		substring = malloc(sizeof(char) * 1);
		if (!substring)
			return (NULL);
		ft_strlcpy(substring, "\0", 1);
		return (substring);
	}
	while (start + llock < ft_strlen(s) && llock < len)
		llock++;
	substring = malloc(sizeof(char) * (llock + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, ps + start, llock + 1);
	return (substring);
}
