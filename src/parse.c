/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:03 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 22:31:33 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_map	*link_ridges(t_map *map)
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
	line = get_lines(src, line);

	//debug -----------
	clock_t begin = clock();
	// --------------

	line = split_lines(first_line(line), line->number);

	//debug -----------
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent split_lines: %f\n", time_spent);
	begin = clock();
	// ---------------

	map = map_init(line, map);

	//debug -----------
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent map_init: %f\n", time_spent);
	// -----------

	line_clear(&line);
	free(line);
	line = NULL;
	map = link_ridges(map);
	return (map);
}
