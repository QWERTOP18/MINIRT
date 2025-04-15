/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:38:09 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:18 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

bool	parse_triangle(t_objects *objs, char **tokens, int line_num)
{
	t_vec			p0;
	t_vec			p1;
	t_vec			p2;
	t_scaled_col	color;
	bool			res;

	res = expect_len(5, tokens, line_num);
	if (!res)
		return (false);
	p0 = parse_vector(&res, tokens[1], line_num);
	p1 = parse_vector(&res, tokens[2], line_num);
	p2 = parse_vector(&res, tokens[3], line_num);
	color = parse_color(&res, tokens[4], line_num);
	if (!res)
		return (false);
	ft_lstadd_back(&(objs->objs), ft_lstnew(TRIANGLE, triangle_new(p0, p1, p2,
				material_init_l(color, line_num))));
	return (true);
}
