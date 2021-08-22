/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:25 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/22 23:15:30 by fcaquard         ###   ########.fr       */
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

int	main(void)
{
	t_lmlx	*lmlx;
	t_map	*map;



	lmlx = lmlx_init();
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, WINDOW_X, WINDOW_Y, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	// map = parse("./maps/basictest.fdf");
	map = parse("./maps/10-70.fdf");
		// map = parse("./maps/square.fdf");
	draw_canvas(lmlx, 0, 0, BORDER);
	draw_middleline(lmlx);

	size_t x;
	size_t y;
	size_t canvas;
	size_t space;

	x = 0;
	y = 0;
	canvas = WINDOW_X - (2 * BORDER);


	while (map->next)
	{
		space = (canvas / map->max_x) / (map->y + 1);
		x = ((WINDOW_X - (space * map->max_x)) / 2) + space * map->x;
		y = ((WINDOW_Y / 2) - map->z) / (map->y + 1);
		mlx_pixel_put(lmlx->mlx, lmlx->window, x, y, GREEN);
		ft_printf("[x: %d/%d, y: %d/%d, %d] \n", map->x,  map->max_x, map->y, map->max_y, map->z);
		map = map->next;
	}

	mlx_loop(lmlx->mlx);
	return (0);
}

