/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/25 17:27:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"
#include <stdio.h>

int	input_hook(int key, void *params)
{
	t_lmlx	*lmlx;

	lmlx = (t_lmlx *)params;
	if (key == 65307)
		input_esc(lmlx);
	else if (key == 65362)
		action_up(lmlx);
	else if (key == 65364)
		action_down(lmlx);
	else if (key == 65363)
		action_right(lmlx);
	else if (key == 65361)
		action_left(lmlx);
	else if (key == 41 || key == 61)
		action_elevation(lmlx, key);
	else if (key == 65451 || key == 65453)
		action_zoom(lmlx, key);
	else if (key == 113 || key == 100)
		action_angle(lmlx, key);
	else if (key == 65289)
		action_rotation(lmlx);
	return (0);
}

t_lmlx	*lmlx_init(void)
{
	t_lmlx	*lmlx;

	lmlx = malloc(sizeof(t_lmlx) * 1);
	if (!lmlx)
		return (NULL);
	lmlx->view = 0;
	lmlx->elevation = 1;
	lmlx->distance = 5;
	lmlx->angle = 0.52;
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	lmlx->baseX = (WINDOW_X / 2);
	lmlx->baseY = (WINDOW_Y / 2);
	return (lmlx);
}

int	main(int argc, char **argv)
{
	t_lmlx	*lmlx;

	if (argc != 2)
		return (0);
	lmlx = lmlx_init();
	if (!lmlx)
		return (0);
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	lmlx->map = parse(argv[1]);
	loop_draw(lmlx->map, lmlx);
	mlx_loop(lmlx->mlx);
	return (0);
}
