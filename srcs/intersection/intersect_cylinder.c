/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 06:43:14 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	intersect_cylinder(t_unit_line ray, const t_cylinder *cy, double t1,
		double t2)
{
	t_intersect	is;

	t_vec p1, p2;
	t_vec v1, v2;
	double h1, h2;
	is.dist = __DBL_MAX__;
	is.material = cy->material;
	p1 = vec_add(ray.pos, vec_mul(ray.dir, t1));
	p2 = vec_add(ray.pos, vec_mul(ray.dir, t2));
	v1 = vec_sub(p1, cy->center);
	v2 = vec_sub(p2, cy->center);
	h1 = fabs(vec_dot(v1, cy->normal));
	h2 = fabs(vec_dot(v2, cy->normal));
	if (h1 < cy->height / 2)
	{
		is.dist = t1;
		is.pos = p1;
		is.normal = vec_normalize(vec_sub(v1, vec_mul(cy->normal, h1)));
	}
	else if (h2 < cy->height / 2)
	{
		is.dist = t2;
		is.pos = p2;
		is.normal = vec_normalize(vec_sub(v2, vec_mul(cy->normal, h2)));
	}
	return (is);
}

/* CYLINDER */
t_intersect	is2(t_unit_line ray, void *obj)
{
	const t_cylinder	*cy = (const t_cylinder *)obj;
	t_intersect			is;
	t_vec				dp;
	t_vec				d_cross_n;
	t_vec				dp_cross_n;
	double				a;
	double				b;
	double				c;
	t_vec				roots;

	dp = vec_sub(ray.pos, cy->center);
	d_cross_n = vec_cross(ray.dir, cy->normal);
	dp_cross_n = vec_cross(dp, cy->normal);
	a = vec_dot(d_cross_n, d_cross_n);
	b = 2 * vec_dot(d_cross_n, dp_cross_n);
	c = vec_dot(dp_cross_n, dp_cross_n) - cy->radius * cy->radius;
	is.dist = __DBL_MAX__;
	roots = solve_eq(a, b, c);
	if ((int)roots.x == 2)
		return (intersect_cylinder(ray, cy, roots.y, roots.z));
	return (is);
}
