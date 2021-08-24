/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:05:22 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 22:27:32 by fcaquard         ###   ########.fr       */
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
	int i;

	i = 0;
	str = NULL;
	o = open(map, O_RDONLY);
	if (o != -1)
	{
		str = get_next_line(o);
		while (str)
		{
			i++;
			line->line = str;
			line = new_line(line);
			line->number = i;
			str = get_next_line(o);
		}
	}
	return (line);
}

t_lines	*split_lines(t_lines *line, size_t nlines)
{
	size_t	nsplits;

	nsplits = 0;
	while (line->next)
	{
		line->splits = ft_split(line->line, ' ');
		if (!line->splits)
			return (NULL);
		line->nlines = nlines;
		if (nsplits == 0)
			nsplits = array_length(line->splits);
		line->nsplits = nsplits;
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
