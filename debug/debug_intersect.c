/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:54:28 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 09:40:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minirt.h"

// SQUARE
/*
* dist functions
半直線rayを受取、
double	dist(t_unit_line *ray, void *data);
距離を返す




*/
// int	calc1(t_unit_line *ray, t_list *lobj, t_camera *camera)
// {
// 	t_vec	camera_vec;
// 	t_vec	sphere_center;
// 	t_vec	screen_vec;
// 	t_vec	dir_vec;
// 	t_vec	camera2sphere_vec;
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	d;
// 	double	sphere_r;

// 	camera_vec = vec(0, 0, -5);
// 	sphere_center = ((t_sphere *)lobj->data)->center;
// 	sphere_r = ((t_sphere *)lobj->data)->radius;
// 	printf("square %f\n", sphere_r);
// }
// //本来ならcolorを返すか、距離を返すか
// return (0);
// }

// PLANE
int	calc2(t_unit_line *ray, t_list *lobj, t_camera *camera)
{
	return (1);
}