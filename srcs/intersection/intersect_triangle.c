/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 15:46:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* TRIANGLE */
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
	// レイが三角形と平行
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
	if (t < FT_EPSILON) // レイの逆方向や原点すぐ後ろ
		return (is);
	// 交差あり
	is.dist = t;
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, t));
	is.normal = tr->normal;
	is.material = tr->material;
	return (is);
}
