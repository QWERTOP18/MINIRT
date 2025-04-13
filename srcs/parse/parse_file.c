/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:27:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 03:18:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parse.h"
// #include <stdio.h>
// #include <stdlib.h>

// t_objects	*parse_file(char *file, t_sys *sys)
// {
// 	int			fd;
// 	t_objects	*objs;
// 	int			i;
// 	char		*line;
// 	char		**tokens;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (NULL);
// 	}
// 	objs = sys->obj;
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		++i;
// 		tokens = ft_split(line, ' ');
// 		if (!tokens)
// 		{
// 			free(line);
// 			perror("Error splitting line");
// 			return (NULL);
// 		}
// 		if (tokens[0][0] == '#')
// 			continue ;
// 		else if (ft_strncmp(tokens[0], "A", 2) == 0)
// 			parse_ambient(objs, tokens, i, sys);
// 		else if (ft_strncmp(tokens[0], "C", 2) == 0)
// 			parse_camera(objs, tokens, i, sys);
// 		else if (ft_strncmp(tokens[0], "L", 2) == 0)
// 			parse_light(objs, tokens, i, sys);
// 		else if (ft_strncmp(tokens[0], "sp", 2) == 0)
// 			parse_sphere(objs, tokens, i, sys);
// 		// else if (ft_strncmp(tokens[0], "pl", 2) == 0)
// 		// 	parse_plane(objs, tokens, i, sys);
// 		// else if (ft_strncmp(tokens[0], "cy", 2) == 0)
// 		// 	parse_cylinder(objs, tokens, i, sys);
// 		else
// 			printf("Error: Unknown object type '%s' at line %d\n", tokens[0],
// 				i);
// 		line = get_next_line(fd);
// 	}
// 	printf("sys->obj file: %p\n", sys->obj);
// 	return (objs);
// }

// /*
// A  0.1      255,255,255
// C  0,3,-20 0,-0.2,1 60
// C  0,3,-20    0,-0.2,1       60
// C  0,3,-20    0,-0.2,1       60

// L  150,150,-150 0.9 255,255,255
// sp 5,0,0       3          255,0,0

// #ライトサブは小文字で判定

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/18 14:27:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 02:53:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

bool	parse_tokens(char **tokens, int line_num, t_objects *objs, t_sys *sys)
{
	// empty line or comment line
	if (!tokens[0] || tokens[0][0] == '#')
		return (true);
	else if (ft_strncmp(tokens[0], "A", 2) == 0)
		parse_ambient(objs, tokens, line_num, sys);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		parse_camera(objs, tokens, line_num, sys);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		parse_light(objs, tokens, line_num, sys);
	else if (ft_strncmp(tokens[0], "sp", 2) == 0)
		parse_sphere(objs, tokens, line_num, sys);
	// else if (ft_strncmp(tokens[0], "pl", 2) == 0)
	// 	parse_plane(objs, tokens, i, sys);
	// else if (ft_strncmp(tokens[0], "cy", 2) == 0)
	// 	parse_cylinder(objs, tokens, i, sys);
	else
		printf("Error: Unknown object type '%s' at line %d\n", tokens[0],
			line_num);
	return (true);
}
bool	parse_line(char *line, int line_num, t_objects *objs, t_sys *sys)
{
	char	**tokens;
	bool	res;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		ft_strs_clear(tokens);
		printf("Error splitting line %s\n", line_num);
		return (false);
	}
	res = parse_tokens(tokens, line_num, objs, sys);
	ft_strs_clear(tokens);
	return (res);
}

t_objects	*parse_file(char *file, t_sys *sys)
{
	int			fd;
	int			i;
	char		*line;
	t_objects	*objects;
	bool		res;

	res = true;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (printf("Error opening file"), NULL);
	}
	objects = ft_calloc(1, sizeof(t_objects));
	i = 0;
	while (++i < MAX_INPUT_LINE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		res = parse_line(line, i, objects, sys);
		free(line);
	}
	if (!res)
		return (free(objects), NULL);
	return (printf("parse %s completed\n", file), objects);
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