#include "../include/FdF.h"

static t_map	*new_map(t_map *previous, int x, int y, int z, size_t max_y, size_t max_x)
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
	map->max_x = max_x;
	map->max_y = max_y;
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

static t_lines	*split_lines(t_lines *line, size_t nlines)
{
	char *temp;

	temp = NULL;
	while (line->next)
	{
		temp = ft_strtrim(line->line, "\n");
		if (!temp)
			return (NULL);
		line->splits = ft_split(temp, ' ');
		line->nsplits = array_length(line->splits);
		line->nlines = nlines;
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
		while (line->splits[x])
		{
			map = new_map(map, x, y, ft_atoi(line->splits[x]), line->nlines, line->nsplits);
			ft_printf("%s ", line->splits[x]);
			x++;
		}
		ft_printf("\n");
		y++;
		x = 0;
		line = line->next;
	}
	return (first_space(map));
}

static void		loop_clear(t_lines **line)
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

t_map			*parse(char *src)
{
	t_lines	*line;
	t_map	*map;

	map = NULL;
	line = new_line(NULL);
	line = get_lines(src, line);
	line = split_lines(line, count_list(first_line(line)));
	map = map_init(line, map);
	// line = first_line(line);
	loop_clear(&line);
	free(line);
	line = NULL;
	return (map);
}
