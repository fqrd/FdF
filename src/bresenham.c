/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:12:47 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 11:14:18 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	bresenham_high(int x0, int y0, int x1, int y1, t_lmlx *lmlx)
{
	int dx;
	int dy;
	int xi;
	int D;
	int x;
	int y;

    dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if (dx < 0)
	{

        xi = -1;
        dx = -dx;
	}
    D = (2 * dx) - dy;
    x = x0;

	y = y0;
	while (y <= y1)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, DEFAULTCOLOR);
		if (D > 0)
		{
			x += xi;
			D = D + (2 * (dx - dy));
		}
		else
			D += 2*dx;
		y++;
	}
}

void	bresenham_low(int x0, int y0, int x1, int y1, t_lmlx *lmlx)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	x;
	int	y;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
	{
        yi = -1;
        dy = -dy;
	}
    D = (2 * dy) - dx;
    y = y0;

	x = x0;
	while (x <= x1)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, DEFAULTCOLOR);
		if (D > 0)
		{
			y += yi;
			D = D + (2 * (dy - dx));
		}
		else
			D += 2*dy;
		x++;
	}
}

void	bresenham(t_coords *cm1, t_coords *cm2, t_lmlx *lmlx)
{
    if (abs(cm2->y - cm1->y) < abs(cm2->x - cm1->x))
	{
        if (cm1->x > cm2->x)
            bresenham_low(cm2->x, cm2->y, cm1->x, cm1->y, lmlx);
        else
            bresenham_low(cm1->x, cm1->y, cm2->x, cm2->y, lmlx);
	}
    else
	{
        if (cm1->y > cm2->y)
            bresenham_high(cm2->x, cm2->y, cm1->x, cm1->y, lmlx);
        else
            bresenham_high(cm1->x, cm1->y, cm2->x, cm2->y, lmlx);
	}
}