/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:46:06 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/12 11:51:32 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/_libft/include/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0X0000FF
# define WINDOW_X 1024
# define WINDOW_Y 650

typedef struct s_lmlx
{
	void *mlx;
	void *window;
}	t_lmlx;

typedef struct	s_lines
{
	char 			*line;
	char			**splits;
	size_t			nsplits;
	size_t			nlines;
	struct s_lines	*previous;
	struct s_lines	*next;
}	t_lines;

typedef struct s_map
{
	char 			*line;
	int				x;
	int				y;
	int				z;
	size_t			max_x;
	size_t			max_y;
	struct s_map	*next;
	struct s_map	*previous;
	struct s_map	*up;
	struct s_map	*down;
}	t_map;

t_map	*parse(char *map);


size_t  array_length(char **array);
size_t  count_list(t_lines  *line);

#endif