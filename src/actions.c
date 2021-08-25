/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/25 23:04:38 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	action_zoom(t_lmlx *lmlx, int bool)
{
	if (bool)
	{
		if (lmlx->distance > 0)
			lmlx->elevation *= ((double)(lmlx->distance + 1) \
				/ (double)lmlx->distance);
		lmlx->distance += 1;
	}
	else
	{
		if (lmlx->distance - 1 > 0)
			lmlx->elevation *= ((double)(lmlx->distance - 1) \
				/ (double)lmlx->distance);
		lmlx->distance -= 1;
	}
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_elevation(t_lmlx *lmlx, int bool)
{
	if (bool)
		lmlx->elevation += 0.2;
	else
		lmlx->elevation -= 0.2;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_angle(t_lmlx *lmlx, int bool)
{
	if (bool)
		lmlx->angle += 0.02;
	else
		lmlx->angle -= 0.02;
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_rotation(t_lmlx *lmlx)
{
	if (lmlx->view == 3)
		lmlx->view = 0;
	else
		lmlx->view++;
	lmlx->flag_rotation = 1;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}
