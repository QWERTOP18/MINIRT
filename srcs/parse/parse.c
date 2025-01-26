/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:38:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/20 10:39:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
C fovが0だったらdiv 0になるので




*/

bool	parse_line(t_objects *objs, char *line, t_sys *sys)
{
	return (true);
}

t_objects	*parse_file(char *file, t_sys *sys)
{
	t_objects	*objects;
	int			fd;
	char		*line;

	LOG;
#ifdef NOINPUT
	sys->width = 1024;
	sys->height = 1024;
	return (generate(sys));
#else
	objects = xcalloc(1, sizeof(t_objects), sys);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_exit(sys, E_INVALID_INPUT);
	line = get_next_line(fd);
	while (line)
	{
		// if (is_valid_line(line))
		//    add_object(objects, line);
		if (!parse_line(objects, line, sys))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
#endif
	return (objects);
}

/*
R  512      512
A  0.1      255,255,255
l  150,150,-150  0.9         255,255,255
c  0,0,-30    0,0,1    45
sp 0,0,0       10          255,0,0
*/