/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:10:21 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 15:41:42 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_cone(t_objects *objs, char **tokens, int line_num)
{
	t_vec			center;
	t_vec			vec_axis;
	t_vec			d_w;
	t_scaled_col	color;
	bool			res;

	// double			diameter;
	// double			height;
	res = expect_len(6, tokens, line_num);
	if (!res)
		return (false);
	center = parse_vector(&res, tokens[1], line_num);
	vec_axis = parse_vector(&res, tokens[2], line_num);
	d_w.x = parse_double(&res, tokens[3], line_num, vec(0, __DBL_MAX__, 1)) / 2;
	d_w.y = parse_double(&res, tokens[4], line_num, vec(0, __DBL_MAX__, 1));
	d_w.z = 0xDEADBEAF;
	color = parse_color(&res, tokens[5], line_num);
	if (!res)
		return (false);
	ft_lstadd_back(&(objs->objs), ft_lstnew(CONE, cone_new(center, vec_axis,
				vec(d_w.x, d_w.y, d_w.z), material_init_l(color, line_num))));
	return (true);
}
