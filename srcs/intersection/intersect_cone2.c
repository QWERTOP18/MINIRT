/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 06:59:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 07:00:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static double	calc_cone_height(t_unit_line ray, const t_cone *cone, double t)
{
	t_vec	hit;
	t_vec	hit_vec;

	hit = vec_add(ray.pos, vec_mul(ray.dir, t));
	hit_vec = vec_sub(hit, cone->vertex);
	return (vec_dot(hit_vec, cone->normal));
}

static t_intersect	get_cone_intersection(t_unit_line ray, const t_cone *cone,
		double t)
{
	t_intersect	is;
	double		h;
	t_vec		hit;
	t_vec		axis_point;
	t_vec		normal;

	is.dist = __DBL_MAX__;
	is.material = cone->material;
	if (t <= 0)
		return (is);
	h = calc_cone_height(ray, cone, t);
	if (h < 0 || h > cone->height)
		return (is);
	hit = vec_add(ray.pos, vec_mul(ray.dir, t));
	axis_point = vec_add(cone->vertex, vec_mul(cone->normal, h));
	normal = vec_normalize(vec_sub(hit, axis_point));
	if (vec_dot(normal, ray.dir) > 0)
		normal = vec_mul(normal, -1);
	is.pos = hit;
	is.normal = normal;
	is.dist = t;
	return (is);
}

t_intersect	intersect_cone(t_unit_line ray, const t_cone *cone, double t1,
		double t2)
{
	t_intersect	is1;
	t_intersect	is2;
	t_intersect	is;

	is1 = get_cone_intersection(ray, cone, t1);
	if (is1.dist != __DBL_MAX__)
		return (is1);
	is2 = get_cone_intersection(ray, cone, t2);
	if (is2.dist != __DBL_MAX__)
		return (is2);
	is.dist = __DBL_MAX__;
	is.material = cone->material;
	return (is);
}
