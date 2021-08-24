/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:25:13 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 18:01:51 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	draw(t_map *map, t_lmlx *lmlx)
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
		bresenham(map, map->previous, lmlx);
	if (map->up)
		bresenham(map, map->up, lmlx);
}

void	loop_draw(t_map *map, t_lmlx *lmlx)
{
	while (map->next)
	{
		draw(map, lmlx);
		map = map->next;
	}
	draw(map, lmlx);
}
