/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 06:38:49 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 14:25:21 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

/* L  0,150,0  0.9         255,255,255 */
bool	parse_light(t_objects *objs, char **tokens, int line, t_sys *sys)
{
	double	intensity;
	t_vec	color;
	bool	res;
	t_vec	pos;

	if (objs->num_of_light >= MAX_LIGHT)
		return (printf("line: %d: too many lights\n", line), false);
	res = expect_len(4, tokens, line);
	if (!res)
		return (false);
	pos = parse_vector(&res, tokens[1], line);
	intensity = parse_double(&res, tokens[2], line, vec(0, 1, 1));
	color = parse_color(&res, tokens[3], line);
	if (!res)
		return (false);
	objs->light[objs->num_of_light++] = light_init(pos, color, intensity, sys);
	return (res);
}

// void	parse_vec3(const char *token, t_light *light)
// {
// 	int			i;
// 	const char	*p = token;
// 	double		value;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		value = ft_atof(&p);
// 		if (i == 0)
// 			light->pos.x = value;
// 		else if (i == 1)
// 			light->pos.y = value;
// 		else if (i == 2)
// 			light->pos.z = value;
// 		if (i < 2)
// 		{
// 			if (*p != ',')
// 				error_exit("Invalid vector format");
// 			p++;
// 		}
// 		i++;
// 	}
// }

// void	parse_light_color(const char *token, t_light *light)
// {
// 	int			i;
// 	const char	*p = token;
// 	double		value;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		value = ft_atoi(p);
// 		printf("value: %f\n", value);
// 		if (i == 0)
// 			light->color.x = value;
// 		else if (i == 1)
// 			light->color.y = value;
// 		else if (i == 2)
// 			light->color.z = value;
// 		while ((*p >= '0' && *p <= '9') || *p == '-' || *p == '+')
// 			p++;
// 		if (i < 2)
// 		{
// 			if (*p != ',')
// 				error_exit("Invalid vector format");
// 			p++;
// 		}
// 		i++;
// 	}
// }

// bool	parse_light(t_objects *objs, char **tokens, int line_num, t_sys *sys)
// {
// 	t_light	*light;
// 	char	*pos_token;
// 	char	*bright_token;
// 	char	*color_token;

// 	pos_token = tokens[1];
// 	bright_token = tokens[2];
// 	color_token = tokens[3];
// 	printf("pos_token: %s\n", pos_token);
// 	printf("bright_token: %s\n", bright_token);
// 	printf("color_token: %s\n", color_token);
// 	if (!pos_token || !bright_token || !color_token)
// 	{
// 		printf("Error: Insufficient tokens for Light at line %d\n", line_num);
// 		return (NULL);
// 	}
// 	light = ft_calloc(1, sizeof(t_light));
// 	parse_vec3(pos_token, light);
// 	light->intensity = ft_atof(&bright_token);
// 	parse_light_color(color_token, light);
// 	objs->light[objs->num_of_light] = light_init(light->pos, light->color,
// 			light->intensity, sys);
// 	objs->num_of_light++;
// 	printf("sys->obj light: %p\n", sys->obj);
// 	return (objs);
// }
/*
A  0.1 255,255,255
C  0,3,-20    0,-0.2,1       60
C  0,3,-20    0,-0.2,1       60
C  0,3,-20    0,-0.2,1       60
L  150,150,-150  0.9         255,255,255
sp 5,0,0       3          255,0,0

#ライトサブは小文字で判定

*/