/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/25 13:02:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_splits(char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int	clearm(char **arr, size_t cell)
{
	arr = arr - cell;
	while (*arr)
		free(*arr++);
	free(arr);
	return (0);
}

static int	assign(char ***array, size_t *cell, char *position, int len)
{
	char	*dest;

	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (clearm(*array, *cell));
	ft_strlcpy(dest, position, len);
	(*array)[(*cell)++] = dest;
	return (1);
}

static char	**split(char **array, char *str, unsigned char c)
{
	size_t	i;
	size_t	start;
	size_t	cell;

	i = 0;
	cell = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			if (!assign(&array, &cell, str + start, (i - start) + 1))
				return (NULL);
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	*ps;
	char	**array;

	ps = (char *) s;
	if (!s)
		return (NULL);
	n = ft_count_splits(ps, c);
	array = malloc(sizeof(char *) * (n + 1));
	if (!array)
		return (NULL);
	array[n] = NULL;
	if (n)
		array = split(array, ps, c);
	if (!array)
		return (NULL);
	return (array);
}
