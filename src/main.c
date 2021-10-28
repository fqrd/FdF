/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/10/28 14:41:31 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static int	input_hook(int key, void *params)
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
	else if (key == 38 || key == 233)
		action_elevation(lmlx, key == 38);
	else if (key == 61 || key == 41)
		action_zoom(lmlx, key == 61);
	else if (key == 34 || key == 39)
		action_angle(lmlx, key == 34);
	else if (key == 65289)
		action_rotation(lmlx);
	return (0);
}

static t_lmlx	*lmlx_init(void)
{
	t_lmlx	*lmlx;

	lmlx = malloc(sizeof(t_lmlx) * 1);
	if (!lmlx)
		return (NULL);
	lmlx->view = 0;
	lmlx->elevation = 1;
	lmlx->distance = 5;
	lmlx->angle = 0.56;
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	lmlx->baseX = (WINDOW_X / 2);
	lmlx->baseY = (WINDOW_Y / 2);
	lmlx->flag_rotation = 1;
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
	lmlx->map = parse(argv[1]);
	if (!lmlx->map)
		return (clear_lmlx(&lmlx));
	lmlx->mlx = mlx_init();
	if (!lmlx->mlx)
		return (clear_lmlx(&lmlx));
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	if (!lmlx->window)
		return (clear_lmlx(&lmlx));
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	if (!loop_draw(lmlx->map, lmlx))
		return (clear_lmlx(&lmlx));
	mlx_loop(lmlx->mlx);
	return (1);
}
