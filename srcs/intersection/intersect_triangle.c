/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/15 17:51:25 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* TRIANGLE */
// t_intersect	is4(t_unit_line ray, void *obj)
// {
// 	t_intersect	is;

// 	(void)ray;
// 	(void)obj;
// 	is.dist = __DBL_MAX__;
// 	is.normal = vec(0, 0, 0);
// 	is.pos = vec(0, 0, 0);
// 	is.material = NULL;
// 	return (is);
// }

t_intersect	is4(t_unit_line ray, void *obj)
{
	const t_triangle	*tr = (const t_triangle *)obj;
	t_intersect			is;

	t_vec e1, e2, h, s, q;
	double a, f, u, v, t;
	e1 = vec_sub(tr->p1, tr->p0);
	e2 = vec_sub(tr->p2, tr->p0);
	h = vec_cross(ray.dir, e2);
	a = vec_dot(e1, h);
	is.dist = __DBL_MAX__;
	is.material = tr->material;
	if (fabs(a) < FT_EPSILON)
		return (is);
	f = 1.0 / a;
	s = vec_sub(ray.pos, tr->p0);
	u = f * vec_dot(s, h);
	if (u < 0.0 || u > 1.0)
		return (is);
	q = vec_cross(s, e1);
	v = f * vec_dot(ray.dir, q);
	if (v < 0.0 || u + v > 1.0)
		return (is);
	t = f * vec_dot(e2, q);
	if (t < FT_EPSILON)
		return (is);
	is.dist = t;
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, t));
	is.normal = tr->normal;
	if (vec_dot(is.normal, ray.dir) > 0)
		is.normal = vec_mul(is.normal, -1);
	return (is);
}
