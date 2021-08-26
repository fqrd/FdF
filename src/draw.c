/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:25:13 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 17:57:12 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static int	draw(t_map *map, t_lmlx *lmlx)
{
	if (lmlx->view == 0)
		map = view_from_top(map, lmlx);
	else if (lmlx->view == 1)
		map = view_from_right(map, lmlx);
	else if (lmlx->view == 2)
		map = view_from_bottom(map, lmlx);
	else
		map = view_from_left(map, lmlx);
	if (map->previous && (map->y == map->previous->y))
	{
		if (!bresenham(map, map->previous, lmlx))
			return (0);
	}
	if (map->up)
	{
		if (!bresenham(map, map->up, lmlx))
			return (0);
	}
	return (1);
}

int	loop_draw(t_map *map, t_lmlx *lmlx)
{
	if (lmlx->flag_rotation)
	{
		lmlx->baseX = WINDOW_X / 2;
		lmlx->baseY = WINDOW_Y / 2;
		if (lmlx->view == 0)
			lmlx->baseY -= (map->max_x * lmlx->distance) / 2;
		if (lmlx->view == 1)
			lmlx->baseX += (map->max_x * lmlx->distance);
		if (lmlx->view == 2)
			lmlx->baseY += (map->max_x * lmlx->distance) / 2;
		if (lmlx->view == 3)
			lmlx->baseX -= (map->max_x * lmlx->distance);
		lmlx->flag_rotation = 0;
	}
	while (map->next)
	{
		if (!draw(map, lmlx))
			return (0);
		map = map->next;
	}
	if (!draw(map, lmlx))
		return (0);
	return (1);
}
