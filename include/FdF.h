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

typedef struct s_lmlx
{
	void *mlx;
	void *window;
}	t_lmlx;

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

int parse(char *map);

#endif