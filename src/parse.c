/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:03 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 20:38:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static t_map	*link_ridges(t_map *map)
{
	while (map->next)
	{
		if (map->x != (int) map->max_x)
		{
			if (map->down)
				map->next->down = map->down->next;
			if (map->up)
				map->next->up = map->up->next;
		}
		map = map->next;
	}
	return (rewind_map(map));
}

t_map	*parse(char *src)
{
	t_lines	*line;
	t_map	*map;

	map = NULL;
	line = new_line(NULL);
	if (!line)
		return (NULL);
	line = get_lines(src, line);
	if (!line)
		return (NULL);
	line = split_lines(first_line(line), line->nlines);
	if (!line)
		return (NULL);
	map = map_init(line, map);
	if (!map)
		return (NULL);
	clear_line_main(&line);
	free(line);
	line = NULL;
	map = link_ridges(map);
	return (map);
}
