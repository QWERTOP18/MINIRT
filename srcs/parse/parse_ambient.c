/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:19:34 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/14 10:07:14 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

bool	parse_ambient(t_objects *objs, char **tokens, int line)
{
	double			ratio;
	t_scaled_col	color;
	bool			res;

	// if (objs->ambient.x != -1)
	// 	return (printf("line: %d: ambient light is already set\n", line),
	// 		false);
	res = expect_len(3, tokens, line);
	if (!res)
		return (false);
	ratio = parse_double(&res, tokens[1], line, vec(0, 1.0, 1));
	color = parse_color(&res, tokens[2], line);
	objs->ambient = vec_mul(color_scaler(color), ratio);
	return (res);
}
