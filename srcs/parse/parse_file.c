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
#include "system.h"

bool	parse_tokens(char **tokens, int line_num, t_objects *objs, t_sys *sys)
{
	if (!tokens[0] || tokens[0][0] == '\n' || tokens[0][0] == '#')
		return (true);
	else if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (parse_ambient(objs, tokens, line_num));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (parse_camera(objs, tokens, line_num, sys));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (parse_light(objs, tokens, line_num, sys));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (parse_sphere(objs, tokens, line_num));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (parse_plane(objs, tokens, line_num));
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (parse_cylinder(objs, tokens, line_num));
	else if (ft_strncmp(tokens[0], "cone", 5) == 0)
		return (parse_cone(objs, tokens, line_num));
	else if (ft_strncmp(tokens[0], "tr", 3) == 0)
		return (parse_triangle(objs, tokens, line_num));
	else
		return (printf("line: %d: Unknown object type '%s'\n", line_num,
				tokens[0]), false);
	return (true);
}

bool	parse_line(char *line, int line_num, t_objects *objs, t_sys *sys)
{
	char	**tokens;
	bool	res;

	res = true;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		ft_strs_clear(tokens);
		printf("Error splitting line %d\n", line_num);
		return (false);
	}
	if (parse_tokens(tokens, line_num, objs, sys) == false)
		res = false;
	ft_strs_clear(tokens);
	return (res);
}

bool	check_objects(t_objects *objs)
{
	bool	res;

	res = true;
	if (objs->ambient.x == -1)
	{
		printf("Ambient is required\n");
		res = false;
	}
	if (objs->num_of_camera == 0)
	{
		printf("Camera is required\n");
		res = false;
	}
	if (objs->num_of_light == 0)
	{
		printf("Light is required\n");
		res = false;
	}
	return (res);
}

/**
 * @param res エラーがあるか
 */
t_objects	*parse_file(char *file, t_sys *sys)
{
	int			fd;
	int			i;
	char		*line;
	t_objects	*objects;
	bool		res;

	res = true;
	fd = open_rtfile(file);
	if (fd < 0)
		return (mlx_destroy_display(sys->mlx), free(sys->mlx), NULL);
	objects = init_objs();
	i = 0;
	while (++i < MAX_INPUT_LINE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		res &= parse_line(line, i, objects, sys);
		free(line);
	}
	if (!res || !check_objects(objects))
		return (deinit_parse_stack(sys, objects), NULL);
	return (printf("parse: %s completed\n", file), objects);
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