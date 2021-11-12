/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:36:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/11/12 14:16:34 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_map	*view_from_top(t_map *map, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		map->wx = lmlx->basex;
		map->wy = (lmlx->basey) + (map->y * (2 * lmlx->height));
		map->wy -= (map->z * lmlx->elevation);
	}	
	else
	{
		if (map->x < map->y)
		{
			map->wx = (lmlx->basex) - ((map->y - map->x) * lmlx->distance);
			map->wy = (lmlx->basey) + (map->y * (2 * lmlx->height)) \
					- ((map->y - map->x) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
		}
		else
		{
			map->wx = (lmlx->basex) + ((map->x - map->y) * lmlx->distance);
			map->wy = (lmlx->basey) + (map->x * (2 * lmlx->height)) \
					- ((map->x - map->y) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
		}
	}
	return (map);
}

t_map	*view_from_right(t_map *map, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		map->wy = lmlx->basey;
		map->wy -= (map->z * lmlx->elevation);
		map->wx = (lmlx->basex) - (map->y * (2 * lmlx->distance));
	}	
	else
	{
		if (map->x < map->y)
		{
			map->wy = (lmlx->basey) - ((map->y - map->x) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
			map->wx = (lmlx->basex) - (map->y * (2 * lmlx->distance)) \
					+ ((map->y - map->x) * lmlx->distance);
		}
		else
		{
			map->wy = (lmlx->basey) + ((map->x - map->y) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
			map->wx = (lmlx->basex) - (map->x * (2 * lmlx->distance)) \
					+ ((map->x - map->y) * lmlx->distance);
		}
	}
	return (map);
}

t_map	*view_from_bottom(t_map *map, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		map->wx = lmlx->basex;
		map->wy = (lmlx->basey) - (map->y * (2 * lmlx->height));
		map->wy -= (map->z * lmlx->elevation);
	}	
	else
	{
		if (map->x < map->y)
		{
			map->wx = (lmlx->basex) + ((map->y - map->x) * lmlx->distance);
			map->wy = (lmlx->basey) - (map->y * (2 * lmlx->height)) \
				+ ((map->y - map->x) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
		}
		else
		{
			map->wx = (lmlx->basex) - ((map->x - map->y) * lmlx->distance);
			map->wy = (lmlx->basey) - (map->x * (2 * lmlx->height)) \
				+ ((map->x - map->y) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
		}
	}
	return (map);
}

t_map	*view_from_left(t_map *map, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		map->wy = lmlx->basey;
		map->wy -= (map->z * lmlx->elevation);
		map->wx = (lmlx->basex) + (map->y * (2 * lmlx->distance));
	}	
	else
	{
		if (map->x < map->y)
		{
			map->wy = (lmlx->basey) + ((map->y - map->x) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
			map->wx = (lmlx->basex) + (map->y * (2 * lmlx->distance)) \
				- ((map->y - map->x) * lmlx->distance);
		}
		else
		{
			map->wy = (lmlx->basey) - ((map->x - map->y) * lmlx->height);
			map->wy -= (map->z * lmlx->elevation);
			map->wx = (lmlx->basex) + (map->x * (2 * lmlx->distance)) \
				- ((map->x - map->y) * lmlx->distance);
		}
	}
	return (map);
}
