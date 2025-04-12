/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 07:33:15 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

double	calc_cylinder_height(t_unit_line ray, const t_cylinder *cy, double t)
{
	t_vec	hit;
	t_vec	hit_vec;

	hit = vec_add(ray.pos, vec_mul(ray.dir, t));
	hit_vec = vec_sub(hit, cy->center);
	return (fabs(vec_dot(hit_vec, cy->normal)));
}

t_intersect	intersect_cylinder(t_unit_line ray, const t_cylinder *cy, double t1,
		double t2)
{
	t_intersect	is;
	double		h;

	t_vec hit, hit_vec, normal;
	is.dist = __DBL_MAX__;
	is.material = cy->material;
	if (t1 > 0)
	{
		h = calc_cylinder_height(ray, cy, t1);
		if (h < cy->height / 2)
		{
			hit = vec_add(ray.pos, vec_mul(ray.dir, t1));
			hit_vec = vec_sub(hit, cy->center);
			normal = vec_normalize(vec_sub(hit_vec, vec_mul(cy->normal,
							vec_dot(hit_vec, cy->normal))));
			is.dist = t1;
			is.pos = hit;
			is.normal = normal;
			return (is);
		}
	}
	if (t2 > 0)
	{
		h = calc_cylinder_height(ray, cy, t2);
		if (h < cy->height / 2)
		{
			hit = vec_add(ray.pos, vec_mul(ray.dir, t2));
			hit_vec = vec_sub(hit, cy->center);
			normal = vec_normalize(vec_sub(hit_vec, vec_mul(cy->normal,
							vec_dot(hit_vec, cy->normal))));
			is.dist = t2;
			is.pos = hit;
			is.normal = vec_mul(normal, -1);
			return (is);
		}
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
	t_vec				coef;
	t_roots				roots;

	dp = vec_sub(ray.pos, cy->center);
	d_cross_n = vec_cross(ray.dir, cy->normal);
	dp_cross_n = vec_cross(dp, cy->normal);
	coef.x = vec_dot(d_cross_n, d_cross_n);
	coef.y = 2 * vec_dot(d_cross_n, dp_cross_n);
	coef.z = vec_dot(dp_cross_n, dp_cross_n) - cy->radius * cy->radius;
	is.dist = __DBL_MAX__;
	roots = solve_eq(coef.x, coef.y, coef.z);
	if (roots.n == 2)
		return (intersect_cylinder(ray, cy, roots.x1, roots.x2));
	return (is);
}
