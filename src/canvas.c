/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:47:51 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/22 19:29:28 by fcaquard         ###   ########.fr       */
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
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
				x++;
			}
			x = 0;
		}
		if (y == bordersize || y == WINDOW_Y - bordersize)
		{
			while (x < WINDOW_X)
			{
				if (x >= bordersize && x <= WINDOW_X - bordersize)
					mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
				x++;
			}
			x = 0;
		}
		y++;
	}
}



void	draw_middleline(t_lmlx *lmlx)
{
	size_t x;

	x = 0;
	while (x < WINDOW_X)
	{
		if (x >= BORDER && x <= WINDOW_X - BORDER)
		{
			mlx_pixel_put(lmlx->mlx, lmlx->window, x, WINDOW_Y/2, BLUE);
		}
		x++;
	}
}