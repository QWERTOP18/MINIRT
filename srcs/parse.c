/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:38:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 01:48:56 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_objects	*parse_file(char *file, t_sys *sys)
{
	t_objects	*objects;
	char		*line;
	int			fd;

	objects = ft_calloc(1, sizeof(t_objects));
	if (!objects)
		system_exit(sys, E_ALLOCATE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_exit(sys, E_INVALID_INPUT);
	line = get_next_line(fd);
	while (line)
	{
		// if (is_valid_line(line))
		// 	add_object(objects, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (objects);
}
