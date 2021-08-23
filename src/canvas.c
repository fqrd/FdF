/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:47:51 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 00:44:56 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	draw_canvas(t_lmlx *lmlx, size_t x, size_t y, size_t bordersize)
{
	while (y < WINDOW_Y)
	{
		if (y > bordersize && y < WINDOW_Y - bordersize)
		{
			while (x < WINDOW_X)
			{
				if (x == bordersize || x == WINDOW_X - bordersize)
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, DEFAULTCOLOR);
				x++;
			}
			x = 0;
		}
		if (y == bordersize || y == WINDOW_Y - bordersize)
		{
			while (x < WINDOW_X)
			{
				if (x >= bordersize && x <= WINDOW_X - bordersize)
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, DEFAULTCOLOR);
				x++;
			}
			x = 0;
		}
		y++;
	}
}
