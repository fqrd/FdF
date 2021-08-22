/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/23 00:29:40 by fcaquard         ###   ########.fr       */
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
	if (key == 65307)
		input_esc(lmlx);
	return (0);
}

t_lmlx	*lmlx_init(void)
{
	t_lmlx	*lmlx;

	lmlx = malloc(sizeof(t_lmlx) * 1);
	if (!lmlx)
		return (NULL);
	return (lmlx);
}


void	bresenham(int x0, int y0, int x1, int y1, t_lmlx *lmlx)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int D = (2 * dy) - dx;
	int y = y0;
	int x = x0;
	while (x <= x1)
	{
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
		if (D > 0)
		{
			y++;
			D = D - 2*dx;
		}
		D = D + 2*dy;
		x++;
	}
}


int	main(void)
{
	t_lmlx	*lmlx;
	t_map	*map;

	lmlx = lmlx_init();
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	map = parse("./maps/basictest.fdf");
	// map = parse("./maps/10-70.fdf");
		// map = parse("./maps/square.fdf");
	// draw_canvas(lmlx, 0, 0, BORDER);
	// draw_middleline(lmlx);

	int x;
	int y;
	int space;
	size_t canvas;
	x = 0;
	y = 0;
	int x1;
	int y1;
	x1 = 0;
	y1 = 0;
	canvas = WINDOW_X - (2 * BORDER);
	while (map->next)
	{
		space = (canvas / map->max_x) / (map->y + 1);
		x = ((WINDOW_X - (space * map->max_x)) / 2) + space * map->x;
		y = ((WINDOW_Y / 2) - map->z) / (map->y + 1);
		x1 = ((WINDOW_X - (space * map->max_x)) / 2) + space * map->next->x;
		y1 = ((WINDOW_Y / 2) - map->next->z) / (map->next->y + 1);
		// bresenham(x, y, x1, y1, lmlx);
		if (map->down)
		{
			x1 = ((WINDOW_X - (space * map->max_x)) / 2) + space * map->down->x;
			y1 = ((WINDOW_Y / 2) - map->down->z) / (map->down->y + 1);
			// ft_printf("map->down (%d,%d,%d)\n", map->down->x,map->down->y,map->down->z);
			bresenham(x, y, x1, y1, lmlx);
		}
		map = map->next;
		// mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
		// ft_printf("[x: %d/%d, y: %d/%d, %d] \n", map->x,  map->max_x, map->y, map->max_y, map->z);
	}

	mlx_loop(lmlx->mlx);
	return (0);
}

