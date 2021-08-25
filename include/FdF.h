/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:46:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/25 16:19:39 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/_libft/include/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <math.h>
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0X0000FF
# define WHITE 0XFFFFFF
# define GRAY 0X93827F
# define DEFAULTCOLOR GRAY

# define WINDOW_X 1024
# define WINDOW_Y 800

typedef struct s_lmlx
{
	void			*mlx;
	void			*window;
	struct s_map	*map;
	int 			view;
	int				elevation;
	int				distance;
	double			height;
	double 			angle;
	int				baseX;
	int				baseY;
	int 			top;
	int 			left;
}	t_lmlx;

typedef struct s_coords
{
	int 	x;
	int 	y;
	int 	distance;
	double 	height;
	int 	elevation;
	int 	base;
}	t_coords;

typedef struct	s_lines
{
	char 			*line;
	char			**splits;
	size_t			nsplits;
	size_t			nlines;
	size_t			number;
	struct s_lines	*previous;
	struct s_lines	*next;
}	t_lines;

typedef struct s_map
{
	char 			*line;
	int				x;
	int				y;
	int				z;
	int				color;
	size_t			max_x;
	size_t			max_y;
	struct s_map	*next;
	struct s_map	*previous;
	struct s_map	*up;
	struct s_map	*down;
	int				wx;
	int				wy;
}	t_map;

// init
t_lmlx	*lmlx_init(void);


// utils
size_t  array_length(char **array);
size_t  count_list(t_lines  *line);

// draw map
void	loop_draw(t_map *map, t_lmlx *lmlx);
void	draw(t_map *map, t_lmlx *lmlx);
void	bresenham(t_map *start, t_map *dest, t_lmlx *lmlx);

// views
t_map	*view_from_left(t_map *map, t_lmlx *lmlx);
t_map	*view_from_top(t_map *map, t_lmlx *lmlx);
t_map	*view_from_bottom(t_map *map, t_lmlx *lmlx);
t_map	*view_from_right(t_map *map, t_lmlx *lmlx);

// lines
t_lines	*new_line(t_lines *previous);
t_lines *first_line(t_lines *line);
t_lines	*get_lines(char *map, t_lines *line);
t_lines	*split_lines(t_lines *line, size_t nlines);
void	line_clear(t_lines **line);

// maps
t_map	*parse(char *map);
t_map	*new_map(t_map *previous, size_t max_y, size_t max_x);
t_map   *rewind_map(t_map *map);
t_map	*map_init(t_lines *line, t_map *map);
t_map	*link_ridges(t_map *map);

// array_test
char	**parse_array(char *src);
char	 **clearsplits(char **split);

// actions
void	input_esc(t_lmlx *lmlx);
void	action_up(t_lmlx *lmlx);
void	action_down(t_lmlx *lmlx);
void	action_right(t_lmlx *lmlx);
void	action_left(t_lmlx *lmlx);
void	action_elevation(t_lmlx *lmlx, int key);
void	action_zoom(t_lmlx *lmlx, int key);
void	action_angle(t_lmlx *lmlx, int key);
void	action_rotation(t_lmlx *lmlx);

#endif