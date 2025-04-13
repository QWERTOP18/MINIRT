/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:10:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 05:19:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_sphere(t_objects *objs, char **tokens, int line)
{
	double			radius;
	t_scaled_col	color;
	bool			res;
	t_vec			center;

	res = expect_len(4, tokens, line);
	if (!res)
		return (false);
	center = parse_vector(&res, tokens[1], line);
	radius = parse_double(&res, tokens[2], line, vec(0, __DBL_MAX__, 1)) / 2;
	color = parse_color(&res, tokens[3], line);
	if (!res)
		return (false);
	ft_lstadd_back(&(objs->objs), ft_lstnew(SPHERE, sphere_new(center, radius,
				material_init_l(color, line))));
	return (res);
}

// typedef struct s_sphere_parse
// {
// 	float	center[3];
// 	float	diameter;
// 	int		color[3];
// }			t_sphere_parse;

// void	parse_vec3_sp(const char *token, float vec[3])
// {
// 	int			i;
// 	const char	*p = token;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		vec[i] = ft_atof(&p);
// 		// if (vec[i] < -1.0 || vec[i] > 1.0)
// 		// 	error_exit("Vector value out of range");
// 		if (i < 2)
// 		{
// 			if (*p != ',')
// 				error_exit("Invalid vector format");
// 			p++;
// 		}
// 		i++;
// 	}
// }

// t_objects	*parse_sphere(t_objects *objs, char **tokens, int line_num,
// 		t_sys *sys)
// {
// 	char			*center_token;
// 	char			*diameter_token;
// 	char			*color_token;
// 	t_sphere_parse	*sp;

// 	center_token = tokens[1];
// 	diameter_token = tokens[2];
// 	color_token = tokens[3];
// 	sp = malloc(sizeof(t_sphere_parse));
// 	if (!sp)
// 		error_exit("Failed to allocate memory for sphere");
// 	printf("center_token: %s\n", center_token);
// 	printf("diameter_token: %s\n", diameter_token);
// 	printf("color_token: %s\n", color_token);
// 	if (!center_token || !diameter_token || !color_token)
// 		error_exit("Insufficient tokens for Sphere");
// 	parse_vec3_sp(center_token, sp->center);
// 	sp->diameter = ft_atof((const char **)&diameter_token);
// 	parse_color(color_token, sp->color);
// 	printf("sys->obj: %p\n", sys->obj);
// 	ft_lstadd_back(&(objs->objs), ft_lstnew(SPHERE,
// 			sphere_new(vec(sp->center[0], sp->center[1], sp->center[2]),
// 				sp->diameter / 2, material_init(vec(sp->color[0], sp->color[1],
// 						sp->color[2])))));
// 	printf("sys->obj sphere: %p\n", sys->obj);
// 	free(sp);
// 	return (objs);
// }