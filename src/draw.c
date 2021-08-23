/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:25:13 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/23 18:49:37 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"


void	getCoords(t_map *map, int *x, int *y, t_coords **coords)
{
	if (map->x == map->y)
	{
		*x = WINDOW_X / 2;
		*y = (WINDOW_Y / 2) - (map->y * (2 * (*coords)->height)) - (map->z * (*coords)->elevation);
	}	
	else
	{
		if (map->x < map->y)
		{
			*y = (WINDOW_Y / 2) - ((map->y * (2 * (*coords)->height)) - ((map->y - map->x) * (*coords)->height) + (map->z * (*coords)->elevation));
			*x = (WINDOW_X / 2) - ((map->y - map->x) * (*coords)->distance);
		}
		else
		{
			*y = (WINDOW_Y / 2) -  ((map->x * (2 * (*coords)->height)) - ((map->x - map->y) * (*coords)->height) + (map->z * (*coords)->elevation));
			*x = (WINDOW_X / 2) + ((map->x - map->y) * (*coords)->distance);
		}
	}
}

void draw(t_map *map, t_lmlx *lmlx)
{
	t_coords *coords;
	coords = malloc (sizeof(t_coords) * 1);
	if (!coords)
		exit(0);

	coords->distance = lmlx->distance;
	coords->height = atan(lmlx->angle) * coords->distance;
	coords->elevation = lmlx->elevation;

	while (map->next)
	{
		if (map->x != (int) map->max_x)
		{
			getCoords(map, &coords->x, &coords->y, &coords);
			getCoords(map->next, &coords->x1, &coords->y1, &coords);
			bresenham(lmlx->left + coords->x, lmlx->top + coords->y, lmlx->left + coords->x1, lmlx->top + coords->y1, lmlx);
		}
		if (map->down)
		{
			getCoords(map->down, &coords->x1, &coords->y1, &coords);
			bresenham(lmlx->left + coords->x, lmlx->top + coords->y, lmlx->left + coords->x1, lmlx->top + coords->y1, lmlx);
		}
		// mlx_pixel_put(lmlx->mlx, lmlx->window, coords->x, coords->y, GREEN);
		map = map->next;
	}
}
