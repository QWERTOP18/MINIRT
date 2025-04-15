/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:10:44 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/14 15:43:09 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_cylinder(t_objects *objs, char **tokens, int line)
{
	t_vec			center;
	t_vec			vec_axis;
	t_vec			d_w;
	t_scaled_col	color;
	bool			res;

	res = expect_len(6, tokens, line);
	if (!res)
		return (false);
	center = parse_vector(&res, tokens[1], line);
	vec_axis = parse_vector(&res, tokens[2], line);
	d_w.x = parse_double(&res, tokens[3], line, vec(0, __DBL_MAX__, 1)) / 2;
	d_w.y = parse_double(&res, tokens[4], line, vec(0, __DBL_MAX__, 1));
	d_w.z = 0xDEADBEAF;
	color = parse_color(&res, tokens[5], line);
	if (!res)
		return (false);
	ft_lstadd_back(&(objs->objs), ft_lstnew(CYLINDER, cylinder_new(center,
				vec_axis, vec(d_w.x, d_w.y, d_w.z), material_init_l(color,
					line))));
	return (true);
}

// cy 50.0, 0.0, 20.6 0.0, 0.0, 1.0 14.2 21.42 10, 0, 255