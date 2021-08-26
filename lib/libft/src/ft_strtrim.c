/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/06 12:29:50 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_char(unsigned char c, char const *test)
{
	size_t			i;

	i = 0;
	while (test[i] && c)
	{
		if (test[i] && (unsigned char) test[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	char	*output;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && check_char((unsigned char) s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && check_char((unsigned char) s1[i], set))
		i--;
	if (i >= start && ft_strlen(s1) > 0)
		return (ft_substr(s1, start, (i - start) + 1));
	output = malloc(sizeof(char) * 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (output);
}
