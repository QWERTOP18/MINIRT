/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 07:41:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	intersect_dispacher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3};

	return (isfunc[obj->type](ray, obj->data));
}

t_list	*determine_target(t_unit_line ray, t_list *objs)
{
	double		dist;
	double		min_dist;
	t_material	*res;
	t_list		*obj;

	res = NULL;
	min_dist = __DBL_MAX__;
	obj = objs;
	while (obj)
	{
		dist = intersect_dispacher(ray, obj).dist;
		if (dist < min_dist)
		{
			min_dist = dist;
			res = obj;
		}
		obj = obj->next;
	}
	return (res);
}

t_scaled_col	cal_diffuse(t_unit_vec lightdir, t_unit_vec normal,
		t_scaled_col intensity, t_scaled_col obj_color)
{
	double	dot_product;

	dot_product = fmax(0.0, vec_dot(lightdir, normal));
	return (vec_mul(vec_hadamard(intensity, obj_color), dot_product));
}
t_scaled_col	cal_specular(t_unit_vec ray_inverse, t_unit_vec lightdir,
		t_unit_vec normal, t_scaled_col intensity)
{
	t_unit_vec	reflection;
	double		n_dot_l;
	double		v_dot_r;

	static double gloss = 400; // todo material->gloss
	n_dot_l = vec_dot(lightdir, normal);
	reflection = vec_normalize(vec_sub(vec_mul(normal, 2 * n_dot_l), lightdir));
	v_dot_r = vec_dot(ray_inverse, reflection);
	if (n_dot_l < 0 || v_dot_r < 0)
		return (vec(0, 0, 0));
	return (vec_mul(intensity, pow(v_dot_r, gloss)));
}

t_scaled_col	cal_col(t_unit_line ray, t_light *light, t_intersect intersect)
{
	t_scaled_col	res;

	t_unit_vec lightdir; //交点から光源へのベクトル
	lightdir = vec_normalize(vec_sub(light->pos, intersect.pos));
	// t_scaled_col coef = vec(0.6, 0.6); // todo materialによって変える
	res = vec(0, 0, 0); // original color
	res = vec_add(res, cal_diffuse(lightdir, intersect.normal, light->intensity,
				intersect.material->color));
	res = vec_add(res, cal_specular(vec_mul(ray.dir, -1), lightdir,
				intersect.normal, light->intensity));
	return (res);
}

unsigned int	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel)
{
	int				i;
	t_scaled_col	sum_color;

	sum_color = vec(0.0, 0.0, 0.0);
	pixel->obj = determine_target(ray, objs->objs);
	if (!pixel->obj)
		return (0);
	pixel->intersect = intersect_dispacher(ray, pixel->obj);
	i = 0;
	while (i < objs->num_of_light)
	{
		pixel->colors[i] = cal_col(ray, objs->light[i], pixel->intersect);
		i++;
	}
	i = 0;
	while (i < objs->num_of_light)
	{
		if (objs->light[i]->ison)
			sum_color = vec_add(sum_color, pixel->colors[i]);
		i++;
	}
	sum_color = vec_add(sum_color, objs->ambient); // todo
	return (color_convert(sum_color));
}
