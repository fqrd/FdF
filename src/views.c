/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:36:34 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 14:37:59 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	view_from_left(t_map *map, t_coords **coords, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		(*coords)->y = lmlx->baseY;
		(*coords)->y -= (map->z * lmlx->elevation);
		(*coords)->x = (lmlx->baseX) + (map->y * (2 * lmlx->distance));
	}	
	else
	{
		if (map->x < map->y)
		{
			(*coords)->y = (lmlx->baseY) - ((map->y - map->x) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
			(*coords)->x = (lmlx->baseX) + (map->y * (2 * lmlx->distance)) - ((map->y - map->x) * lmlx->distance);
		}
		else
		{
			(*coords)->y = (lmlx->baseY) + ((map->x - map->y) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
			(*coords)->x = (lmlx->baseX) + (map->x * (2 * lmlx->distance)) - ((map->x - map->y) * lmlx->distance);
		}
	}	
}

void	view_from_right(t_map *map, t_coords **coords, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		(*coords)->y = lmlx->baseY;
		(*coords)->y -= (map->z * lmlx->elevation);
		(*coords)->x = (lmlx->baseX) - (map->y * (2 * lmlx->distance));
	}	
	else
	{
		if (map->x < map->y)
		{
			(*coords)->y = (lmlx->baseY) + ((map->y - map->x) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
			(*coords)->x = (lmlx->baseX) - (map->y * (2 * lmlx->distance)) + ((map->y - map->x) * lmlx->distance);
		}
		else
		{
			(*coords)->y = (lmlx->baseY) - ((map->x - map->y) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
			(*coords)->x = (lmlx->baseX) - (map->x * (2 * lmlx->distance)) + ((map->x - map->y) * lmlx->distance);
		}
	}	
}

void	view_from_bottom(t_map *map, t_coords **coords, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		(*coords)->x = lmlx->baseX;
		(*coords)->y = (lmlx->baseY) - (map->y * (2 * (*coords)->height));
		(*coords)->y -= (map->z * lmlx->elevation);
	}	
	else
	{
		if (map->x < map->y)
		{
			(*coords)->x = (lmlx->baseX) - ((map->y - map->x) * lmlx->distance);
			(*coords)->y = (lmlx->baseY) - (map->y * (2 * (*coords)->height)) + ((map->y - map->x) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
		}
		else
		{
			(*coords)->x = (lmlx->baseX) + ((map->x - map->y) * lmlx->distance);
			(*coords)->y = (lmlx->baseY) - (map->x * (2 * (*coords)->height)) + ((map->x - map->y) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
		}
	}	
}

void	view_from_top(t_map *map, t_coords **coords, t_lmlx *lmlx)
{
	if (map->x == map->y)
	{
		(*coords)->x = lmlx->baseX;
		(*coords)->y = (lmlx->baseY) + (map->y * (2 * (*coords)->height));
		(*coords)->y -= (map->z * lmlx->elevation);
	}	
	else
	{
		if (map->x < map->y)
		{
			(*coords)->x = (lmlx->baseX) + ((map->y - map->x) * lmlx->distance);
			(*coords)->y = (lmlx->baseY) + (map->y * (2 * (*coords)->height)) - ((map->y - map->x) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
		}
		else
		{
			(*coords)->x = (lmlx->baseX) - ((map->x - map->y) * lmlx->distance);
			(*coords)->y = (lmlx->baseY) + (map->x * (2 * (*coords)->height)) - ((map->x - map->y) * (*coords)->height);
			(*coords)->y -= (map->z * lmlx->elevation);
		}
	}	
}
