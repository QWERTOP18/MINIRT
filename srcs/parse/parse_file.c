/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:27:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/13 17:37:52 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

t_objects	*parse_file(char *file, t_sys *sys)
{
	int			fd;
	t_objects	*objs;
	int			i;
	char		*line;
	char		**tokens;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	objs = sys->obj;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		++i;
		tokens = ft_split(line, ' ');
		if (!tokens)
		{
			free(line);
			perror("Error splitting line");
			return (NULL);
		}
		if (ft_strncmp(tokens[0], "A", 2) == 0)
			parse_ambient(objs, tokens, i, sys);
		else if (ft_strncmp(tokens[0], "C", 2) == 0)
			parse_camera(objs, tokens, i, sys);
		else if (ft_strncmp(tokens[0], "L", 2) == 0)
			parse_light(objs, tokens, i, sys);
		else if (ft_strncmp(tokens[0], "sp", 2) == 0)
			parse_sphere(objs, tokens, i, sys);
		// else if (ft_strncmp(tokens[0], "pl", 2) == 0)
		// 	parse_plane(objs, tokens, i, sys);
		// else if (ft_strncmp(tokens[0], "cy", 2) == 0)
		// 	parse_cylinder(objs, tokens, i, sys);
		else
			printf("Error: Unknown object type '%s' at line %d\n", tokens[0],
				i);
		line = get_next_line(fd);
	}
	printf("sys->obj file: %p\n", sys->obj);
	return (objs);
}

/*
A  0.1      255,255,255
C  0,3,-20 0,-0.2,1 60
C  0,3,-20    0,-0.2,1       60
C  0,3,-20    0,-0.2,1       60

L  150,150,-150 0.9 255,255,255
sp 5,0,0       3          255,0,0

#ライトサブは小文字で判定

*/