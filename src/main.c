// gcc src/*.c -L./libs/minilibx-linux -lmlx -lXext -lX11 -lbsd -L./libs/_libft -lft && ./a.out

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
	map = parse("./maps/basictest.fdf");
	while (map->next)
	{
		ft_printf("[%d, %d, %d] \n", map->x, map->y, map->z);
		mlx_pixel_put(lmlx->mlx, lmlx->window, map->x, map->y, GREEN);
		map = map->next;
	}
	mlx_pixel_put(lmlx->mlx, lmlx->window, map->x, map->y, GREEN);
	ft_printf("[%d, %d, %d] \n", map->x, map->y, map->z);
	mlx_loop(lmlx->mlx);
	return (0);
}
