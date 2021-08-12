// gcc main.c parse.c -L../libs/minilibx-linux -lmlx -lXext -lX11 -lbsd -L../libs/_libft -lft && ./a.out

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

	lmlx = lmlx_init();
	lmlx->mlx = mlx_init();
	lmlx->window = mlx_new_window(lmlx->mlx, 800, 600, "FdF");
	mlx_key_hook(lmlx->window, &input_hook, lmlx);
	parse("/home/fcaquard/code/projects/FdF/extra/test_maps/basictest.fdf");
	mlx_loop(lmlx->mlx);
	return (0);
}
