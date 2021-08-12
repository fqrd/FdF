/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:07:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/12 22:18:51 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_map	*new_map(t_map *previous, size_t max_y, size_t max_x)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->line = NULL;
	map->next = NULL;
	map->previous = previous;
	map->up = NULL;
	map->down = NULL;
	map->max_x = max_x;
	map->max_y = max_y;
	if (previous)
		previous->next = map;
	return (map);
}

t_map	*first_space(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->previous)
		map = map->previous;
	return (map);
}

t_map	*map_init(t_lines *line, t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (line->next)
	{
		while (line->splits[x])
		{
			map = new_map(map, line->nlines, line->nsplits);
			map->x = x;
			map->y = y;
			map->z = ft_atoi(line->splits[x]);
			ft_printf("%s ", line->splits[x]);
			x++;
		}
		ft_printf("\n");
		y++;
		x = 0;
		line = line->next;
	}
	return (first_space(map));
}
