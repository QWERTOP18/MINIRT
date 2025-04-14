/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:10:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 09:55:58 by aryamamo         ###   ########.fr       */
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
