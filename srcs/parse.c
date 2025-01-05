/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:38:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 04:43:06 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "system.h"

t_objects	*parse_file(char *file, t_sys *sys)
{
	t_objects *objects;
	int fd;
	char *line;

	objects = ft_calloc(1, sizeof(t_objects));
	if (!objects)
		system_exit(sys, E_ALLOCATE);

#ifdef NOINPUT

	objects->num_of_camera = 2;
	objects->id_of_camera = 0;
	printf("parse\n");
	objects->camera[0] = *camera_init(vec(0, 0, 0), vec(0, 0, -1), 90, sys);
	objects->camera[1] = *camera_init(vec(0, 0, 5), vec(0, 1, 0), 90, sys);
	for (size_t hh = 0; hh < 100; hh++)
	{
		for (size_t ww = 100; ww < 200; ww++)
		{
			render_pixel(&objects->camera[0].img, ww, hh, 0xFF0000);
		}
	}

#else
	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_exit(sys, E_INVALID_INPUT);
	line = get_next_line(fd);
	while (line)
	{
		// if (is_valid_line(line))
		//    add_object(objects, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
#endif

	return (objects);
}