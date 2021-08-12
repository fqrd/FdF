#include "../include/FdF.h"

static t_map	*new_map(t_map *previous, int x, int y, int z)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->x = x;
	map->y = y;
	map->z = z;
	map->line = NULL;
	map->next = NULL;
	map->previous = previous;
	map->up = NULL;
	map->down = NULL;
	if (previous)
		previous->next = map;
	return (map);
}

static t_map	*first_space(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->previous)
		map = map->previous;
	return (map);
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
		line = line->previous;
	return (line);
}

static t_lines	*get_lines(char *map, t_lines *line)
{
	int		o;
	char	*str;
	
	str = NULL;
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
	return (first_line(line));
}

static t_lines	*split_lines(t_lines *line)
{
	char *temp;

	temp = NULL;
	while (line->next)
	{
		temp = ft_strtrim(line->line, "\n");
		if (!temp)
			return (NULL);
		line->splits = ft_split(temp, ' ');
		if (!line->splits)
			return (NULL);
		free(temp);
		temp = NULL;
		line = line->next;
	}
	return (first_line(line));
}

static t_map	*map_init(t_lines *line, t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (line->next)
	{
		while (line->splits[y])
		{
			map = new_map(map, x, y, ft_atoi(line->splits[y]));
			ft_printf("%s ", line->splits[y]);
			y++;
		}
		ft_printf("\n");
		x++;
		y = 0;
		line = line->next;
	}
	return (first_space(map));
}

/**
	char 			*line;
	char			**splits;
	struct s_lines	*previous;
	struct s_lines	*next;
*/

static void	loop_clear(t_lines **line)
{
	size_t i;
	t_lines *tmp;

	i = 0;
	while ((*line)->next)
	{
		while ((*line)->splits[i])
		{
			free((*line)->splits[i]);
			(*line)->splits[i] = NULL;
			i++;
		}
		free((*line)->splits);
		(*line)->splits = NULL;
		free((*line)->line);
		(*line)->line = NULL;
		tmp = (*line)->next;
		free (*line);
		*line = tmp;
		i = 0;
	}
}

t_map	*parse(char *src)
{
	t_lines	*line;
	t_map	*map;

	map = NULL;
	line = new_line(NULL);
	line = get_lines(src, line);
	line = split_lines(line);
	map = map_init(line, map);
	line = first_line(line);
	loop_clear(&line);
	free(line);
	line = NULL;
	return (map);
}
