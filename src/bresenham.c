/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:12:47 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 17:52:43 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static t_brshm	*bhm_init(void)
{
	t_brshm	*bhm;

	bhm = malloc(sizeof(t_brshm) * 1);
	if (!bhm)
		return (NULL);
	bhm->dx = 0;
	bhm->dy = 0;
	bhm->xi = 0;
	bhm->yi = 0;
	bhm->D = 0;
	bhm->x = 0;
	bhm->y = 0;
	return (bhm);
}

static void	bhm_high(t_map *start, t_map *dest, t_lmlx *lmlx, t_brshm *bhm)
{
	bhm->dx = dest->wx - start->wx;
	bhm->dy = dest->wy - start->wy;
	bhm->xi = 1;
	if (bhm->dx < 0)
	{
		bhm->xi = -1;
		bhm->dx = -bhm->dx;
	}
	bhm->D = (2 * bhm->dx) - bhm->dy;
	bhm->x = start->wx;
	bhm->y = start->wy;
	while (bhm->y <= dest->wy)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, bhm->x, bhm->y, start->color);
		if (bhm->D > 0)
		{
			bhm->x += bhm->xi;
			bhm->D = bhm->D + (2 * (bhm->dx - bhm->dy));
		}
		else
			bhm->D += 2 * bhm->dx;
		bhm->y++;
	}
}

static void	bhm_low(t_map *start, t_map *dest, t_lmlx *lmlx, t_brshm *bhm)
{
	bhm->dx = dest->wx - start->wx;
	bhm->dy = dest->wy - start->wy;
	bhm->yi = 1;
	if (bhm->dy < 0)
	{
		bhm->yi = -1;
		bhm->dy = -bhm->dy;
	}
	bhm->D = (2 * bhm->dy) - bhm->dx;
	bhm->y = start->wy;
	bhm->x = start->wx;
	while (bhm->x <= dest->wx)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, bhm->x, bhm->y, start->color);
		if (bhm->D > 0)
		{
			bhm->y += bhm->yi;
			bhm->D = bhm->D + (2 * (bhm->dy - bhm->dx));
		}
		else
			bhm->D += 2 * bhm->dy;
		bhm->x++;
	}
}

int	bresenham(t_map *start, t_map *dest, t_lmlx *lmlx)
{
	t_brshm	*bhm;

	bhm = bhm_init();
	if (!bhm)
		return (0);
	if (abs(dest->wy - start->wy) < abs(dest->wx - start->wx))
	{
		if (start->wx > dest->wx)
			bhm_low(dest, start, lmlx, bhm);
		else
			bhm_low(start, dest, lmlx, bhm);
	}
	else
	{
		if (start->wy > dest->wy)
			bhm_high(dest, start, lmlx, bhm);
		else
			bhm_high(start, dest, lmlx, bhm);
	}
	free(bhm);
	return (1);
}
