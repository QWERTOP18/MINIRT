/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:10:44 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/13 17:24:08 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

typedef struct s_sphere_parse
{
	float	center[3];
	float	diameter;
	int		color[3];
}			t_sphere_parse;

void	parse_vec3_sp(const char *token, float vec[3])
{
	int			i;
	const char	*p = token;

	i = 0;
	while (i < 3)
	{
		vec[i] = ft_atof(&p);
		// if (vec[i] < -1.0 || vec[i] > 1.0)
		// 	error_exit("Vector value out of range");
		if (i < 2)
		{
			if (*p != ',')
				error_exit("Invalid vector format");
			p++;
		}
		i++;
	}
}

void	parse_color(const char *token, int color[3])
{
	int			i;
	const char	*p = token;

	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(p);
		printf("color[%d]: %d\n", i, color[i]);
		if (color[i] < 0 || color[i] > 255)
			error_exit("Color value out of range");
		while ((*p >= '0' && *p <= '9') || *p == '-' || *p == '+')
			p++;
		if (i < 2)
		{
			if (*p != ',')
				error_exit("Invalid color format");
			p++;
		}
		i++;
	}
}

t_objects	*parse_sphere(t_objects *objs, char **tokens, int line_num,
		t_sys *sys)
{
	char			*center_token;
	char			*diameter_token;
	char			*color_token;
	t_sphere_parse	*sp;

	center_token = tokens[1];
	diameter_token = tokens[2];
	color_token = tokens[3];
	sp = malloc(sizeof(t_sphere_parse));
	if (!sp)
		error_exit("Failed to allocate memory for sphere");
	printf("center_token: %s\n", center_token);
	printf("diameter_token: %s\n", diameter_token);
	printf("color_token: %s\n", color_token);
	if (!center_token || !diameter_token || !color_token)
		error_exit("Insufficient tokens for Sphere");
	parse_vec3_sp(center_token, sp->center);
	sp->diameter = ft_atof((const char **)&diameter_token);
	parse_color(color_token, sp->color);
	printf("sys->obj: %p\n", sys->obj);
	ft_lstadd_back(&(sys->obj->objs), ft_lstnew(SPHERE,
			sphere_new(vec(sp->center[0], sp->center[1], sp->center[2]),
				sp->diameter, material_init(vec(sp->color[0], sp->color[1],
						sp->color[2])))));
	printf("sys->obj sphere: %p\n", sys->obj);
	free(sp);
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