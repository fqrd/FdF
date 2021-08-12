/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:03 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/12 22:13:57 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

t_map	*parse(char *src)
{
	t_lines	*line;
	t_map	*map;

	map = NULL;
	line = new_line(NULL);
	line = get_lines(src, line);
	line = split_lines(line, count_list(first_line(line)));
	map = map_init(line, map);
	line_clear(&line);
	free(line);
	line = NULL;
	return (map);
}
