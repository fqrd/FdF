/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 00:39:49 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	input_esc(t_lmlx *lmlx)
{
	ft_printf("ESC\n");
	if (lmlx)
	{
		mlx_destroy_window(lmlx->mlx, lmlx->window);
		exit(0);
	}
}

int	input_hook(int key, void *params)
{
	t_lmlx	*lmlx;

	lmlx = (t_lmlx *)params;
	ft_printf("key: %d\n", key);
	// ESC
	if (key == 65307)
	{
		input_esc(lmlx);
	}
	// UP
	if (key == 65362)
	{
		lmlx->top+=25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// DOWN
	if (key == 65364)
	{
		lmlx->top-=25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// RIGHT
	if (key == 65363)
	{
		lmlx->left-=25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// LEFT
	if (key == 65361)
	{
		lmlx->left+=25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// +
	if (key == 41)
	{
		lmlx->elevation+=1;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// -
	if (key == 61)
	{
		lmlx->elevation-=1;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// +
	if (key == 65451)
	{
		lmlx->distance+=1;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// -
	if (key == 65453)
	{
		lmlx->distance-=1;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// Turn q
	if (key == 113)
	{
		lmlx->angle+=0.02;
		printf("angle: %f\n", lmlx->angle);
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// TURN d
	if (key == 100)
	{
		lmlx->angle-=0.02;
		printf("angle: %f\n", lmlx->angle);
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	return (0);
}

t_lmlx	*lmlx_init(void)
{
	t_lmlx	*lmlx;

	lmlx = malloc(sizeof(t_lmlx) * 1);
	if (!lmlx)
		return (NULL);
	if (WINDOW_Y == WINDOW_X)
		lmlx->base = WINDOW_Y / 2;
	else
	{
		if (WINDOW_Y > WINDOW_X)
			lmlx->base = WINDOW_X / 2;
		else
			lmlx->base = WINDOW_Y / 2;
	}
	lmlx->elevation = 1;
	lmlx->distance = 12;
	lmlx->angle = -0.2;
	lmlx->top = 0;
	lmlx->left = 0;
	return (lmlx);
}

int	main(void)
{
	t_lmlx	*lmlx;
	lmlx = lmlx_init();
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	// lmlx->map = parse("./maps/42.fdf");
	// lmlx->map = parse("./maps/10-70.fdf");
	// lmlx->map = parse("./maps/julia.fdf");
	lmlx->map = parse("./maps/elem-col.fdf");
	// lmlx->map = parse("./maps/mars.fdf");

	// draw_canvas(lmlx, 0, 0, BORDER);
	// draw_middleline(lmlx);

	draw(lmlx->map, lmlx);
	mlx_loop(lmlx->mlx);
	return (0);
}

