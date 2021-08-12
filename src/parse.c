#include "../include/FdF.h"

static t_map	*new_space(t_map *previous, int x, int y, int z)
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

static t_map	*first_space(t_map *space)
{
	if (!space)
		return (NULL);
	while (space->previous)
	{
		space = space->previous;
	}
	return (space);
}

static t_lines	*new_line(t_lines *previous)
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

static t_lines	*first_line(t_lines *line)
{
	if (!line)
		return (NULL);
	while (line->previous)
	{
		line = line->previous;
	}
	return (line);
}

int	parse(char *map)
{
	int		o;
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
	o = open(map, O_RDONLY);
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
