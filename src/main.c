/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 21:57:58 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

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

static void	getWindowCenter(t_lmlx **lmlx)
{
	if (WINDOW_Y == WINDOW_X)
	{
		(*lmlx)->baseX = (WINDOW_Y / 2);
		(*lmlx)->baseY = (WINDOW_Y / 2);
	}
	else
	{
		if (WINDOW_Y > WINDOW_X)
		{
			(*lmlx)->baseX = (WINDOW_X / 2);
			(*lmlx)->baseY = (WINDOW_X / 2);
		}
		else
		{
			(*lmlx)->baseX = (WINDOW_Y / 2);
			(*lmlx)->baseY = (WINDOW_Y / 2);
		}
	}
}

t_lmlx	*lmlx_init(void)
{
	t_lmlx	*lmlx;

	lmlx = malloc(sizeof(t_lmlx) * 1);
	if (!lmlx)
		return (NULL);
	getWindowCenter(&lmlx);
	lmlx->view = 0;
	lmlx->elevation = 1;
	lmlx->distance = 5;
	lmlx->angle = -0.6;
	lmlx->height = atan(lmlx->angle) * lmlx->distance;
	return (lmlx);
}

int	main(int argc, char **argv)
{
	t_lmlx	*lmlx;

	// debug
	clock_t begin = clock();

	if (argc != 2)
		return (0);
	lmlx = lmlx_init();
	if (!lmlx)
		return (0);
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	
	// debug
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent prior parsing: %f\n", time_spent);
	begin = clock();
	
	lmlx->map = parse(argv[1]);

	// debug
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent parsing: %f\n", time_spent);
	begin = clock();

	loop_draw(lmlx->map, lmlx);

	//debug
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent drawing: %f\n", time_spent);


	mlx_loop(lmlx->mlx);
	return (0);
}
