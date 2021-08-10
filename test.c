#include "minilibx-linux/mlx.h"
#include "_libft/include/libft.h"

typedef struct s_core
{
	void *mlx;
	void *window;
}	t_core;

int input_hook(int key, void *params)
{

	t_core *core = (t_core *)params; 

	ft_printf("key: %d\n", key);
	if (key == 65307)
	{
		ft_printf("ESC\n");
		if (core)
		{
			mlx_destroy_window(core->mlx, core->window);
			exit(0);
		}
	}
	return (0);
}


int main(void)
{
	t_core *core;

	core->mlx = mlx_init();
	core->window = mlx_new_window(core->mlx, 500, 500, "FdF");
	mlx_key_hook(core->window, &input_hook, core);
	mlx_loop(core->mlx);
	return (0);
}

// gcc test.c -L./minilibx-linux -lmlx -lXext -lX11 -lbsd -L./_libft -lft && ./a.out