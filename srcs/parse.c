/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:38:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 09:27:07 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	*parse_file(char *file, t_sys *sys)
{
	t_objects *objects;
	int fd;
	char *line;
	LOG;
	objects = ft_calloc(1, sizeof(t_objects));
	if (!objects)
		system_exit(sys, E_ALLOCATE);

#ifdef NOINPUT

	return (generate(sys));

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