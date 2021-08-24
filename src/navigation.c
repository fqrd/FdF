/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:37:41 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 21:38:00 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	action_up(t_lmlx *lmlx)
{
	lmlx->baseY += 25;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_down(t_lmlx *lmlx)
{
	lmlx->baseY -= 25;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_left(t_lmlx *lmlx)
{
	lmlx->baseX += 25;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}

void	action_right(t_lmlx *lmlx)
{
	lmlx->baseX -= 25;
	mlx_clear_window(lmlx->mlx, lmlx->window);
	loop_draw(lmlx->map, lmlx);
}