/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:19:34 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/14 04:32:22 by ymizukam         ###   ########.fr       */
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

	res = expect_len(3, tokens, line);
	if (!res)
		return (false);
	ratio = parse_double(&res, tokens[1], line);
	color = parse_color(&res, tokens[2], line);
	objs->ambient = vec_mul(color_scaler(color), ratio);
	return (res);
}
