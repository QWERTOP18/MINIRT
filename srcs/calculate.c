/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:35:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 13:48:23 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scaled_col	cal_diffuse(t_unit_vec lightdir, t_unit_vec normal,
		t_light *light, t_scaled_col obj_color)
{
	double	dot_product;

	dot_product = fmax(0.0, vec_dot(lightdir, normal));
	return (vec_mul(vec_hadamard(light->color, obj_color), dot_product));
}
t_scaled_col	cal_specular(t_unit_vec ray_inverse, t_unit_vec lightdir,
		t_unit_vec normal, t_light *light)
{
	t_unit_vec	reflection;
	double		n_dot_l;
	double		v_dot_r;

	static double gloss = 600; // todo material->gloss
	n_dot_l = vec_dot(lightdir, normal);
	reflection = vec_normalize(vec_sub(vec_mul(normal, 2 * n_dot_l), lightdir));
	v_dot_r = vec_dot(ray_inverse, reflection);
	if (n_dot_l < 0 || v_dot_r < 0)
		return (vec(0, 0, 0));
	return (vec_mul(light->color, pow(v_dot_r, gloss)));
}

/**
 * objectが光源の内側にあるか判定
 */
int	is_external(t_vec lightdir, t_vec normal)
{
	if (vec_dot(lightdir, normal) > 0)
		return (1);
	return (-1);
}

bool	is_interrupted(t_light *light, t_intersect is, t_list *objs)
{
	t_list		*target;
	double		dist_to_light;
	t_unit_line	light_ray;

	light_ray = unit_line2(is.pos, light->pos);
	//自己交差しないように
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

* cal_col は、与えられた光線 (ray)、光源 (light)、および交差点 (intersect) を基に、最終的な色を計算する関数です。拡散反射と鏡面反射を考慮し、最終的な色を返します。
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
				intersect.material->color));
	res = vec_add(res, cal_specular(vec_mul(ray.dir, -1), lightdir,
				intersect.normal, light));
	return (res);
}
