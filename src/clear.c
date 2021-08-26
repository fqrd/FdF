/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:33:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 20:40:36 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static void	clear_line(t_lines *line)
{
	size_t	i;

	i = 0;
	if (line->splits)
	{
		while (line->splits[i])
		{
			free(line->splits[i]);
			line->splits[i] = NULL;
			i++;
		}
		free(line->splits);
		line->splits = NULL;
	}
	if (line->line)
	{
		free(line->line);
		line->line = NULL;
	}
	free(line);
}

void	*clear_line_main(t_lines **line)
{
	t_lines	*tmp;

	*line = first_line(*line);
	while (*line)
	{
		tmp = (*line)->next;
		clear_line(*line);
		*line = tmp;
	}
	return (NULL);
}

void	*clear_map(t_map **map)
{
	t_map	*tmp;

	*map = rewind_map(*map);
	while (*map)
	{
		tmp = (*map)->next;
		free(*map);
		*map = tmp;
	}
	return (NULL);
}

int	clear_lmlx(t_lmlx **lmlx)
{
	if ((*lmlx)->map)
	{
		clear_map(&(*lmlx)->map);
		free((*lmlx)->map);
	}
	free(*lmlx);
	return (0);
}
