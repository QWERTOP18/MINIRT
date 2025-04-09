/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 05:25:56 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**

	* determine_target は、与えられた光線 (t_unit_line ray) とオブジェクトのリスト (t_list *objs) を基に、光線と交差する最も近いオブジェクトを特定し、そのオブジェクトをリストの要素として返す関数です。交差距離を計算し、最小距離のオブジェクトを選択します。
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

	static double gloss = 400; // todo material->gloss
	n_dot_l = vec_dot(lightdir, normal);
	reflection = vec_normalize(vec_sub(vec_mul(normal, 2 * n_dot_l), lightdir));
	v_dot_r = vec_dot(ray_inverse, reflection);
	if (n_dot_l < 0 || v_dot_r < 0)
		return (vec(0, 0, 0));
	return (vec_mul(light->color, pow(v_dot_r, gloss)));
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

	t_unit_vec lightdir; //交点から光源へのベクトル
	lightdir = vec_normalize(vec_sub(light->pos, intersect.pos));
	// t_scaled_col coef = vec(0.6, 0.6); // todo materialによって変える
	res = vec(0, 0, 0); // original color
	if (is_interrupted(light, intersect, objs))
		return (res);
	res = vec_add(res, cal_diffuse(lightdir, intersect.normal, light,
				intersect.material->color));
	res = vec_add(res, cal_specular(vec_mul(ray.dir, -1), lightdir,
				intersect.normal, light));
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
	pixel->intersect = intersect_dispatcher(ray, pixel->obj);
	i = 0;
	while (i < objs->num_of_light)
	{
		pixel->colors[i] = vec_mul(cal_col(ray, objs->light[i],
					pixel->intersect, objs->objs), objs->light[i]->intensity);
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
