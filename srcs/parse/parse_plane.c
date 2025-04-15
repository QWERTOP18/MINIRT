/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:10:41 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 12:40:56 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_plane(t_objects *objs, char **tokens, int line)
{
	t_vec			plane_vector;
	t_scaled_col	color;
	bool			res;
	t_vec			plane_point;

	res = expect_len(4, tokens, line);
	if (!res)
		return (false);
	plane_point = parse_vector(&res, tokens[1], line);
	plane_vector = parse_vector(&res, tokens[2], line);
	color = parse_color(&res, tokens[3], line);
	if (!res)
		return (false);
	ft_lstadd_back(&(objs->objs), ft_lstnew(PLANE, plane_new(plane_point,
				plane_vector, material_init_l(color, line))));
	return (res);
}
/*
 identifier pl
 pl position x,y,z double
 vector x,y,z double
 color r,g,b int
 pl 0.0,0.0,-10.0  0.0,1.0,0.0  0,0,225
 */