/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/16 11:47:55 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 *交差距離を計算し、最小距離のオブジェクトを選択します。
 */
t_list	*determine_target(t_unit_line ray, t_list *objs)
{
	double	dist;
	double	min_dist;
	t_list	*res;
	t_list	*obj;

	res = NULL;
	min_dist = __DBL_MAX__;
	obj = objs;
	while (obj)
	{
		dist = intersect_dispatcher(ray, obj).dist;
		if (dist > 0 && dist < min_dist)
		{
			min_dist = dist;
			res = obj;
		}
		obj = obj->next;
	}
	return (res);
}

t_unit_line	reflect(t_unit_line ray, t_intersect is)
{
	t_unit_line	reflected;
	t_unit_vec	n;
	t_unit_vec	v;
	double		dot;
	t_unit_vec	reflect_dir;

	n = is.normal;
	v = ray.dir;
	dot = vec_dot(v, n);
	reflect_dir = vec_sub(v, vec_mul(n, 2.0 * dot));
	// r = v- 2(v・n)n
	reflect_dir = vec_normalize(reflect_dir);
	reflected.pos = vec_add(is.pos, vec_mul(reflect_dir, FT_EPSILON));
	reflected.dir = reflect_dir;
	return (reflected);
}

unsigned int	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel)
{
	int				i;
	t_scaled_col	sum_color;

	sum_color = vec(0.0, 0.0, 0.0);
	pixel->obj = determine_target(ray, objs->objs);
	if (!pixel->obj)
		return (0);
	pixel->intersect = intersect_dispatcher(ray, pixel->obj);
	// if (pixel->intersect.material->mirror)
	// 	return (update_pixel(reflect(ray, pixel->intersect), objs, pixel));
	i = 0;
	while (i < objs->num_of_light)
	{
		pixel->colors[i] = cal_col(ray, objs->light[i], pixel->intersect,
				objs->objs);
		i++;
	}
	i = 0;
	while (i < objs->num_of_light)
	{
		if (objs->light[i]->ison)
			sum_color = vec_add(sum_color, pixel->colors[i]);
		i++;
	}
	sum_color = vec_add(sum_color, objs->ambient);
	return (color_convert(sum_color));
}
