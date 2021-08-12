/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:47:51 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/12 22:20:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	draw_canvas(t_lmlx *lmlx, size_t x, size_t y)
{
	while (y < WINDOW_Y)
	{
		if (y > 50 && y < WINDOW_Y - 50)
		{
			while (x < WINDOW_X)
			{
				if (x == 50 || x == WINDOW_X - 50)
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
				x++;
			}
			x = 0;
		}
		if (y == 50 || y == WINDOW_Y - 50)
		{
			while (x < WINDOW_X)
			{
				if (x >= 50 && x <= WINDOW_X - 50)
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
				x++;
			}
			x = 0;
		}
		y++;
	}
}
