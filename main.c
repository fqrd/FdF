#include "./_libft/include/libft.h"

typedef struct	s_lines
{
	char 			*line;
	char			**splits;
	struct s_lines	*previous;
	struct s_lines	*next;
}	t_lines;

typedef struct s_map
{
	char 			*line;
	int				x;
	int				y;
	int				z;
	struct s_map	*next;
	struct s_map	*previous;
	struct s_map	*up;
	struct s_map	*down;
}	t_map;

t_map	*new_space(t_map *previous, int x, int y, int z)
{
	t_map	*space;

	space = malloc(sizeof(t_map) * 1);
	if (!space)
		return (NULL);
	space->x = x;
	space->y = y;
	space->z = z;
	space->line = NULL;
	space->next = NULL;
	space->previous = previous;
	space->up = NULL;
	space->down = NULL;
	if (previous)
		previous->next = space;
	return (space);
}

t_map	*first_space(t_map *space)
{
	if (!space)
		return (NULL);
	while (space->previous)
	{
		space = space->previous;
	}
	return (space);
}

t_lines	*new_line(t_lines *previous)
{
	t_lines	*line;

	line = malloc(sizeof(t_lines) * 1);
	if (!line)
		return (NULL);
	line->line = NULL;
	line->next = NULL;
	line->previous = previous;
	if (previous)
		previous->next = line;
	return (line);
}

t_lines	*first_line(t_lines *line)
{
	if (!line)
		return (NULL);
	while (line->previous)
	{
		line = line->previous;
	}
	return (line);
}


int main(void)
{
	int 	o;
	t_map	*space;
	t_lines	*line;
	char	*str;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	str = NULL;
	line = new_line(NULL);
	space = NULL;
	o = open("./extra/maps/test_maps/10-70.fdf", O_RDONLY);
	if (o != -1)
	{
		str = get_next_line(o);
		while (str)
		{   
			line->line = str;
			line = new_line(line);
			str = get_next_line(o);
		}
	}
	line = first_line(line);

	while (line->next)
	{
		line->splits = ft_split(ft_strtrim(line->line, "\n"), ' '); 
		line = line->next;
	}

	line = first_line(line);

	while (line->next)
	{
		while (line->splits[y])
		{
			space = new_space(space, x, y, ft_atoi(line->splits[y]));
			ft_printf("%s ", line->splits[y]);
			y++;
		}
		ft_printf("\n");
		x++;
		y = 0;
		line = line->next;
	}

	space = first_space(space);

	while (space->next)
	{
		ft_printf("[%d, %d, %d] \n", space->x, space->y, space->z);
		space = space->next;
	}
	ft_printf("[%d, %d, %d] \n", space->x, space->y, space->z);

	return (0);
}