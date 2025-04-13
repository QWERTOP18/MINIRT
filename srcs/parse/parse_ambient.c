/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:19:34 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/13 17:23:30 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

t_objects	*parse_ambient(t_objects *objs, char **tokens, int line, t_sys *sys)
{
	double	ratio;
	char	**color_tokens;

	double r, g, b;
	if (!tokens[1] || !tokens[2])
	{
		fprintf(stderr,
			"Error: Insufficient parameters for ambient light at line %d\n",
			line);
		return (NULL);
	}
	ratio = atof(tokens[1]);
	printf("ratio: %f\n", ratio);
	color_tokens = ft_split(tokens[2], ',');
	printf("color_tokens: %s\n", color_tokens[0]);
	if (!color_tokens)
	{
		fprintf(stderr, "Error: Failed to split color components at line %d\n",
			line);
		return (NULL);
	}
	r = atof(color_tokens[0]);
	g = atof(color_tokens[1]);
	b = atof(color_tokens[2]);
	printf("r: %f, g: %f, b: %f\n", r, g, b);
	objs->ambient = vec((r / 255.0) * ratio, (g / 255.0) * ratio, (b / 255.0)
			* ratio);
	printf("ambient: %f, %f, %f\n", objs->ambient.x, objs->ambient.y,
		objs->ambient.z);
	printf("sys->obj: %p\n", sys->obj);
	printf("objs ambient: %p\n", objs);
	return (objs);
}
