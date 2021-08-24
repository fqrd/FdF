/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/24 15:57:00 by fcaquard         ###   ########.fr       */
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
		lmlx->baseY += 25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// DOWN
	if (key == 65364)
	{
		lmlx->baseY -= 25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// RIGHT
	if (key == 65363)
	{
		lmlx->baseX -= 25;
		mlx_clear_window(lmlx->mlx, lmlx->window);
		draw(lmlx->map, lmlx);
	}
	// LEFT
	if (key == 65361)
	{
		lmlx->baseX += 25;
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
	// TAB Rotation
	if (key == 65289)
	{
		if (lmlx->view == 3)
			lmlx->view = 0;
		else
			lmlx->view++;
		printf("view: %d\n", lmlx->view);
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
	{
		lmlx->baseX = (WINDOW_Y / 2);
		lmlx->baseY = (WINDOW_Y / 2);
	}
	else
	{
		if (WINDOW_Y > WINDOW_X)
		{
			lmlx->baseX = (WINDOW_X / 2);
			lmlx->baseY = (WINDOW_X / 2);
		}
		else
		{
			lmlx->baseX = (WINDOW_Y / 2);
			lmlx->baseY = (WINDOW_Y / 2);
		}
	}
	lmlx->elevation = 1;
	lmlx->distance = 24;
	lmlx->angle = -0.6;
	lmlx->view = 0;
	return (lmlx);
}

int	main(void)
{
	t_lmlx	*lmlx;
	lmlx = lmlx_init();
	if (!lmlx)
		return (0);
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	// lmlx->map = parse("./maps/10-2.fdf");
	// lmlx->map = parse("./maps/10-70.fdf");
	// lmlx->map = parse("./maps/20-60.fdf");
	// lmlx->map = parse("./maps/42.fdf");
	// lmlx->map = parse("./maps/50-4.fdf");
	// lmlx->map = parse("./maps/100-6.fdf");
	// lmlx->map = parse("./maps/basictest.fdf");
	// lmlx->map = parse("./maps/elem-col.fdf");
	// lmlx->map = parse("./maps/elem.fdf");
	// lmlx->map = parse("./maps/elem2.fdf");
	// lmlx->map = parse("./maps/mars.fdf");
	// lmlx->map = parse("./maps/pentenegpos.fdf");
	// lmlx->map = parse("./maps/plat.fdf");
	// lmlx->map = parse("./maps/pnp_flat.fdf");
	// lmlx->map = parse("./maps/pylone.fdf");
	// lmlx->map = parse("./maps/pyra.fdf");
	// lmlx->map = parse("./maps/pyramide.fdf");
	// lmlx->map = parse("./maps/square.fdf");
	// lmlx->map = parse("./maps/t1.fdf");
	// lmlx->map = parse("./maps/t2.fdf");
	// lmlx->map = parse("./maps/test.fdf");

	// SLOW
	lmlx->map = parse("./maps/elem-fract.fdf");
	// lmlx->map = parse("./maps/julia.fdf");
	
	
	draw(lmlx->map, lmlx);
	mlx_loop(lmlx->mlx);
	return (0);
}

