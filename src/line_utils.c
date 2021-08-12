/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:05:22 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/12 22:21:09 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_lines	*new_line(t_lines *previous)
{
	t_lines	*line;

	line = malloc(sizeof(t_lines) * 1);
	if (!line)
		return (NULL);
	line->line = NULL;
	line->next = NULL;
	line->previous = previous;
	if (previous)
		previous->next = line;
	return (line);
}

t_lines	*first_line(t_lines *line)
{
	if (!line)
		return (NULL);
	while (line->previous)
		line = line->previous;
	return (line);
}

t_lines	*get_lines(char *map, t_lines *line)
{
	int		o;
	char	*str;

	str = NULL;
	o = open(map, O_RDONLY);
	if (o != -1)
	{
		str = get_next_line(o);
		while (str)
		{
			line->line = str;
			line = new_line(line);
			str = get_next_line(o);
		}
	}
	return (first_line(line));
}

t_lines	*split_lines(t_lines *line, size_t nlines)
{
	char	*temp;

	temp = NULL;
	while (line->next)
	{
		temp = ft_strtrim(line->line, "\n");
		if (!temp)
			return (NULL);
		line->splits = ft_split(temp, ' ');
		line->nsplits = array_length(line->splits);
		line->nlines = nlines;
		if (!line->splits)
			return (NULL);
		free(temp);
		temp = NULL;
		line = line->next;
	}
	return (first_line(line));
}

void	line_clear(t_lines **line)
{
	size_t	i;
	t_lines	*tmp;

	i = 0;
	while ((*line)->next)
	{
		while ((*line)->splits[i])
		{
			free((*line)->splits[i]);
			(*line)->splits[i] = NULL;
			i++;
		}
		free((*line)->splits);
		(*line)->splits = NULL;
		free((*line)->line);
		(*line)->line = NULL;
		tmp = (*line)->next;
		free (*line);
		*line = tmp;
		i = 0;
	}
}
