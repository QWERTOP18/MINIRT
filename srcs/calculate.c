/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:35:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 06:30:39 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dot_product = fabs(vec_dot(lightdir, normal));
t_scaled_col	cal_diffuse(t_unit_vec lightdir, t_unit_vec normal,
		t_light *light, t_material *material)
{
	double	dot_product;

	dot_product = fmax(0.0, vec_dot(lightdir, normal));
	return (vec_mul(vec_hadamard(light->color, material->color), dot_product
			* material->k_diffuse));
}

t_scaled_col	cal_specular(t_line rayinv_light, t_unit_vec normal,
		t_light *light, t_material *material)
{
	t_unit_vec	ray_inverse;
	double		n_dot_l;
	double		v_dot_r;
	t_unit_vec	lightdir;
	t_unit_vec	reflection;

	ray_inverse = rayinv_light.p1;
	lightdir = rayinv_light.p2;
	n_dot_l = vec_dot(lightdir, normal);
	reflection = vec_normalize(vec_sub(vec_mul(normal, 2 * n_dot_l), lightdir));
	v_dot_r = vec_dot(ray_inverse, reflection);
	if (n_dot_l < 0 || v_dot_r < 0)
		return (vec(0, 0, 0));
	return (vec_mul(light->color, pow(v_dot_r, material->gloss)
			* material->k_specular));
}

bool	is_interrupted(t_light *light, t_intersect is, t_list *objs)
{
	t_list		*target;
	double		dist_to_light;
	t_unit_line	light_ray;

	light_ray = unit_line2(is.pos, light->pos);
	light_ray.pos = vec_add(light_ray.pos, vec_mul(light_ray.dir, FT_EPSILON));
	target = determine_target(light_ray, objs);
	if (!target)
		return (False);
	dist_to_light = vec_distance(light->pos, is.pos);
	if (intersect_dispatcher(light_ray, target).dist < dist_to_light)
		return (True);
	return (False);
}

/**

* 影の計算　拡散反射と鏡面反射
*/
t_scaled_col	cal_col(t_unit_line ray, t_light *light, t_intersect intersect,
		t_list *objs)
{
	t_scaled_col	res;
	t_unit_vec		lightdir;

	lightdir = vec_normalize(vec_sub(light->pos, intersect.pos));
	res = vec(0, 0, 0);
	if (is_interrupted(light, intersect, objs))
		return (res);
	res = vec_add(res, cal_diffuse(lightdir, intersect.normal, light,
				intersect.material));
	res = vec_add(res, cal_specular(line(vec_mul(ray.dir, -1), lightdir),
				intersect.normal, light, intersect.material));
	return (res);
}
