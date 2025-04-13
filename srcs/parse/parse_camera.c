/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:46:17 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/13 14:02:09 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	parse_vec3_cam(const char *token, t_vec *vec, bool check_range)
{
	int			i;
	const char	*p = token;
	double		value;

	i = 0;
	while (i < 3)
	{
		value = ft_atof(&p);
		printf("value: %f\n", value);
		if (check_range && (value < -1.0 || value > 1.0))
			error_exit("Vector value out of range");
		if (i == 0)
			vec->x = value;
		else if (i == 1)
			vec->y = value;
		else if (i == 2)
			vec->z = value;
		if (i < 2)
		{
			if (*p != ',')
				error_exit("Invalid vector format");
			p++;
		}
		i++;
	}
}

t_objects	*parse_camera(t_objects *objs, char **tokens, int line_num,
		t_sys *sys)
{
	t_camera	*cam;
	char		*pos_token;
	char		*dir_token;
	char		*fov_token;
	t_pos_vec	pos;
	t_unit_vec	dir;
	double		fov;

	pos_token = tokens[1];
	dir_token = tokens[2];
	fov_token = tokens[3];
	if (!pos_token || !dir_token || !fov_token)
		error_exit("Insufficient tokens for Camera");
	parse_vec3_cam(pos_token, (t_vec *)&pos, false);
	parse_vec3_cam(dir_token, (t_vec *)&dir, true);
	fov = ft_atoi(fov_token);
	cam = camera_init(pos, dir, fov, sys);
	if (!cam)
		error_exit("Failed to initialize camera");
	objs->camera[objs->num_of_camera] = cam;
	objs->num_of_camera++;
	return (objs);
}

/*
A  0.1 255,255,255
C  0,3,-20    0,-0.2,1       60
C  0,3,-20    0,-0.2,1       60
C  0,3,-20    0,-0.2,1       60
L  150,150,-150  0.9         255,255,255
sp 5,0,0       3          255,0,0

#ライトサブは小文字で判定

*/