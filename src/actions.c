/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:17:32 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 21:38:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	action_zoom(t_lmlx *lmlx, int key)
{
	if (key == 65451)
		lmlx->distance += 1;
	else
		lmlx->distance -= 1;
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_elevation(t_lmlx *lmlx, int key)
{
	if (key == 41)
		lmlx->elevation += 1;
	else
		lmlx->elevation -= 1;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_angle(t_lmlx *lmlx, int key)
{
	if (key == 113)
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
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}
