/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:12:47 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/25 23:20:41 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	bresenham_high(t_map *start, t_map *dest, t_lmlx *lmlx)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	int	x;
	int	y;

	dx = dest->wx - start->wx;
	dy = dest->wy - start->wy;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	x = start->wx;
	y = start->wy;
	while (y <= dest->wy)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, start->color);
		if (D > 0)
		{
			x += xi;
			D = D + (2 * (dx - dy));
		}
		else
			D += 2 * dx;
		y++;
	}
}

void	bresenham_low(t_map *start, t_map *dest, t_lmlx *lmlx)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	x;
	int	y;

	dx = dest->wx - start->wx;
	dy = dest->wy - start->wy;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	y = start->wy;
	x = start->wx;
	while (x <= dest->wx)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, start->color);
		if (D > 0)
		{
			y += yi;
			D = D + (2 * (dy - dx));
		}
		else
			D += 2 * dy;
		x++;
	}
}

void	bresenham(t_map *start, t_map *dest, t_lmlx *lmlx)
{
	if (abs(dest->wy - start->wy) < abs(dest->wx - start->wx))
	{
		if (start->wx > dest->wx)
			bresenham_low(dest, start, lmlx);
		else
			bresenham_low(start, dest, lmlx);
	}
	else
	{
		if (start->wy > dest->wy)
			bresenham_high(dest, start, lmlx);
		else
			bresenham_high(start, dest, lmlx);
	}
}
