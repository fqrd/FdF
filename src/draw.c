/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:25:13 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 12:42:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_coords	*coords_init(t_lmlx *lmlx)
{
	t_coords *coords;
	
	coords = malloc (sizeof(t_coords) * 1);
	if (!coords)
		return (NULL);

	coords->height = atan(lmlx->angle) * lmlx->distance;

	return (coords);
}

void	draw(t_map *map, t_lmlx *lmlx)
{
	t_coords *current;
	t_coords *next;
	t_coords *down;

	current = coords_init(lmlx);
	next = coords_init(lmlx);
	down = coords_init(lmlx);

	while (map->next)
	{
		if (lmlx->view == 0)
		{
			view_from_top(map, &current, lmlx);
			view_from_top(map->next, &next, lmlx);
			if (map->down)
				view_from_top(map->down, &down, lmlx);
		}
		else if (lmlx->view == 1)
		{
			view_from_right(map, &current, lmlx);
			view_from_right(map->next, &next, lmlx);
			if (map->down)
				view_from_right(map->down, &down, lmlx);

		}
		else if (lmlx->view == 2)
		{
			view_from_bottom(map, &current, lmlx);
			view_from_bottom(map->next, &next, lmlx);
			if (map->down)
				view_from_bottom(map->down, &down, lmlx);
		}
		else
		{
			view_from_left(map, &current, lmlx);
			view_from_left(map->next, &next, lmlx);
			if (map->down)
				view_from_left(map->down, &down, lmlx);
		}
		if (map->x != (int) map->max_x)
			bresenham(current, next, lmlx);
		bresenham(current, down, lmlx);
		map = map->next;
	}

}