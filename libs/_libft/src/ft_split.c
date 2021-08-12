/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:34:49 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/06 12:28:36 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_splits(char *str, char c)
{
	size_t	count;
	size_t	i;
	int		new;

	new = 1;
	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] == c)
		{
			if (new == 1)
			{
				new = 0;
				count++;
			}
		}
		else
			new = 1;
		i++;
	}
	return (count);
}

static char	*trimmer(char *str, char c)
{
	int	start;
	int	end;

	if (!str)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (start <= end && str[start] && str[start] == c)
		start++;
	while (end >= 0 && str[end] && str[end] == c)
		end--;
	return (ft_substr(str, start, ((end + 1) - start)));
}

static char	**cmalloc(char *sub, char **arr, size_t cell)
{
	arr[cell] = sub;
	if (!arr[cell])
	{
		arr = arr - cell;
		while (*arr)
			free(*arr++);
		free(arr);
		return (NULL);
	}
	return (arr);
}

static char	**split(char **array, char *str, unsigned char c)
{
	size_t	i;
	size_t	start;
	size_t	cell;

	cell = 0;
	start = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
		{
			if (!cmalloc(ft_substr(str, start, (i - start)), array, cell))
				return (NULL);
			cell++;
			while (str[i] && str[i] == c)
				i++;
			start = i;
		}
		i++;
	}
	if (!cmalloc(ft_substr(str, start, (i - start)), array, cell))
		return (NULL);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	*ps;
	char	**array;

	if (!s)
		return (NULL);
	n = 0;
	ps = trimmer((char *) s, c);
	if (!ps)
		return (NULL);
	if (ft_strlen(ps))
		n = ft_count_splits(ps, c) + 1;
	array = malloc(sizeof(char *) * (n + 1));
	if (!array)
		return (NULL);
	array[n] = NULL;
	if (n)
		array = split(array, ps, c);
	free(ps);
	if (!array)
		return (NULL);
	return (array);
}
