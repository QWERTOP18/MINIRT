/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 06:42:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	is3(t_unit_line ray, void *obj)
{
	const t_cone	*cone = (const t_cone *)obj;
	t_intersect		is;
	t_vec			v;
	t_vec			co;
	double			k;
	double			dv;
	double			cov;
	t_vec			d_minus_vdv;
	t_vec			co_minus_vcov;
	double			a;
	double			b;
	double			c;
	double			t;
	t_vec			hit;
	t_vec			hit_vec;
	double			h;
	t_vec			axis_point;
	t_vec			normal;
	t_vec			roots;

	is.dist = __DBL_MAX__;
	v = cone->normal;
	co = vec_sub((t_vec){ray.pos.x - cone->vertex.x, ray.pos.y - cone->vertex.y,
			ray.pos.z - cone->vertex.z}, (t_vec){0, 0, 0});
	k = tan(cone->angle);
	dv = vec_dot(ray.dir, v);
	cov = vec_dot(co, v);
	d_minus_vdv = vec_sub(ray.dir, vec_mul(v, dv));
	co_minus_vcov = vec_sub(co, vec_mul(v, cov));
	a = vec_dot(d_minus_vdv, d_minus_vdv) - k * k * dv * dv;
	b = 2 * (vec_dot(d_minus_vdv, co_minus_vcov) - k * k * dv * cov);
	c = vec_dot(co_minus_vcov, co_minus_vcov) - k * k * cov * cov;
	roots = solve_eq(a, b, c);
	if (roots.x < 1)
		return (is);
	t = (roots.y > 0) ? roots.y : ((roots.z > 0) ? roots.z : -1);
	if (t < 0)
		return (is);
	hit = vec_add((t_vec){ray.pos.x, ray.pos.y, ray.pos.z}, vec_mul(ray.dir,
				t));
	hit_vec = vec_sub(hit, (t_vec){cone->vertex.x, cone->vertex.y,
			cone->vertex.z});
	h = vec_dot(hit_vec, v);
	if (h < 0 || h > cone->height)
		return (is);
	// 法線の計算
	axis_point = vec_add((t_vec){cone->vertex.x, cone->vertex.y,
			cone->vertex.z}, vec_mul(v, h));
	normal = vec_normalize(vec_sub(hit, axis_point));
	is.pos = (t_pos_vec){hit.x, hit.y, hit.z};
	is.normal = normal;
	is.dist = t;
	is.material = (t_material *)cone->material;
	return (is);
}
