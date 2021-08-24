/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:07:27 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 21:41:46 by fcaquard         ###   ########.fr       */
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
	map->color = DEFAULTCOLOR;
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

t_map	*rewind_map(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->previous)
		map = map->previous;
	return (map);
}

int	extractColor(t_map **map, char *str)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(str, ',');
	if (!split)
		return (-1);
	(*map)->z = ft_atoi(split[0]);
	(*map)->color = ft_atoi_hex(split[1]);
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
	return (1);
}

t_map	*map_init(t_lines *line, t_map *map)
{
	size_t	x;
	size_t	y;
	t_map	*link;

	x = 0;
	y = 0;
	link = NULL;
	while (line->next)
	{
		while (line->splits[x])
		{
			map = new_map(map, line->nlines, line->nsplits);
			map->x = x;
			map->y = y;
			if (ft_charpos(line->splits[x], ',') > 0)
			{
				if (extractColor(&map, line->splits[x]) == -1)
					return (NULL);
			}
			else
				map->z = ft_atoi(line->splits[x]);
			if (x == 0)
			{
				map->up = link;
				if (map->up)
					map->up->down = map;
				link = map;
			}
			x++;
		}
		y++;
		x = 0;
		line = line->next;
	}
	return (rewind_map(map));
}
