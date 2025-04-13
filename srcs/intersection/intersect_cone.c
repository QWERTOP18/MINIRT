/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 15:47:01 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

double	calc_cone_height(t_unit_line ray, const t_cone *cone, double t)
{
	t_vec	hit;
	t_vec	hit_vec;

	hit = vec_add(ray.pos, vec_mul(ray.dir, t));
	hit_vec = vec_sub(hit, cone->vertex);
	return (vec_dot(hit_vec, cone->normal));
}

t_intersect	intersect_cone(t_unit_line ray, const t_cone *cone, double t1,
		double t2)
{
	t_intersect	is;
	double		h;

	t_vec v, hit, axis_point, normal;
	is.dist = __DBL_MAX__;
	is.material = cone->material;
	v = cone->normal;
	if (t1 > 0)
	{
		h = calc_cone_height(ray, cone, t1);
		if (h >= 0 && h <= cone->height)
		{
			hit = vec_add(ray.pos, vec_mul(ray.dir, t1));
			axis_point = vec_add(cone->vertex, vec_mul(v, h));
			normal = vec_normalize(vec_sub(hit, axis_point));
			if (vec_dot(normal, ray.dir) > 0)
				normal = vec_mul(normal, -1);
			is.pos = (t_pos_vec){hit.x, hit.y, hit.z};
			is.normal = normal;
			is.dist = t1;
			return (is);
		}
	}
	if (t2 > 0)
	{
		h = calc_cone_height(ray, cone, t2);
		if (h >= 0 && h <= cone->height)
		{
			hit = vec_add(ray.pos, vec_mul(ray.dir, t2));
			axis_point = vec_add(cone->vertex, vec_mul(v, h));
			normal = vec_normalize(vec_sub(hit, axis_point));
			if (vec_dot(normal, ray.dir) > 0)
				normal = vec_mul(normal, -1);
			is.pos = (t_pos_vec){hit.x, hit.y, hit.z};
			is.normal = normal;
			is.dist = t2;
			return (is);
		}
	}
	return (is);
}

/* CONE */
t_intersect	is3(t_unit_line ray, void *obj)
{
	const t_cone	*cone = (const t_cone *)obj;
	t_intersect		is;
	t_roots			roots;

	t_vec v, co, d_minus_vdv, co_minus_vcov, coef;
	double k, dv, cov;
	v = cone->normal;
	co = vec_sub(ray.pos, cone->vertex);
	k = tan(cone->angle);
	dv = vec_dot(ray.dir, v);
	cov = vec_dot(co, v);
	d_minus_vdv = vec_sub(ray.dir, vec_mul(v, dv));
	co_minus_vcov = vec_sub(co, vec_mul(v, cov));
	coef.x = vec_dot(d_minus_vdv, d_minus_vdv) - k * k * dv * dv;
	coef.y = 2 * (vec_dot(d_minus_vdv, co_minus_vcov) - k * k * dv * cov);
	coef.z = vec_dot(co_minus_vcov, co_minus_vcov) - k * k * cov * cov;
	is.dist = __DBL_MAX__;
	roots = solve_eq(coef.x, coef.y, coef.z);
	if (roots.n == 2)
		return (intersect_cone(ray, cone, roots.x1, roots.x2));
	return (is);
}
