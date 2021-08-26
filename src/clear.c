/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:33:39 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 17:57:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static void	clear_line(t_lines *line)
{
	size_t	i;

	i = 0;
	if (line->splits)
	{
		while (line->splits[i])
		{
			free(line->splits[i]);
			line->splits[i] = NULL;
			i++;
		}
		free(line->splits);
		line->splits = NULL;
	}
	if (line->line)
	{
		free(line->line);
		line->line = NULL;
	}
	free(line);
}

void	*clear_line_main(t_lines **line)
{
	t_lines	*tmp;

	while (*line)
	{
		tmp = (*line)->next;
		clear_line(*line);
		*line = tmp;
	}
	return (NULL);
}
