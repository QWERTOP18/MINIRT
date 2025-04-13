/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 07:01:29 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static double	calc_cylinder_height(t_unit_line ray, const t_cylinder *cy,
		double t)
{
	t_vec	hit;
	t_vec	hit_vec;

	hit = vec_add(ray.pos, vec_mul(ray.dir, t));
	hit_vec = vec_sub(hit, cy->center);
	return (fabs(vec_dot(hit_vec, cy->normal)));
}

static t_intersect	get_cylinder_intersection(t_unit_line ray,
		const t_cylinder *cy, double t)
{
	t_intersect	is;
	double		h;
	t_vec		hit;
	t_vec		hit_vec;
	t_vec		normal;

	is.dist = __DBL_MAX__;
	is.material = cy->material;
	h = calc_cylinder_height(ray, cy, t);
	if (h < cy->height / 2 && t > 0)
	{
		hit = vec_add(ray.pos, vec_mul(ray.dir, t));
		hit_vec = vec_sub(hit, cy->center);
		normal = vec_normalize(vec_sub(hit_vec, vec_mul(cy->normal,
						vec_dot(hit_vec, cy->normal))));
		is.dist = t;
		is.pos = hit;
		is.normal = normal;
	}
	return (is);
}

t_intersect	intersect_cylinder(t_unit_line ray, const t_cylinder *cy, double t1,
		double t2)
{
	t_intersect	is1;
	t_intersect	is2;
	t_intersect	is;

	is1 = get_cylinder_intersection(ray, cy, t1);
	if (is1.dist != __DBL_MAX__)
		return (is1);
	is2 = get_cylinder_intersection(ray, cy, t2);
	if (is2.dist != __DBL_MAX__)
	{
		is2.normal = vec_mul(is2.normal, -1);
		return (is2);
	}
	is.dist = __DBL_MAX__;
	is.material = cy->material;
	return (is);
}

/* CYLINDER */
t_intersect	is2(t_unit_line ray, void *obj)
{
	const t_cylinder	*cy = (const t_cylinder *)obj;
	t_vec				d_cross_n;
	t_vec				dp_cross_n;
	t_vec				coef;
	t_roots				roots;

	d_cross_n = vec_cross(ray.dir, cy->normal);
	dp_cross_n = vec_cross(vec_sub(ray.pos, cy->center), cy->normal);
	coef.x = vec_dot(d_cross_n, d_cross_n);
	coef.y = 2 * vec_dot(d_cross_n, dp_cross_n);
	coef.z = vec_dot(dp_cross_n, dp_cross_n) - cy->radius * cy->radius;
	roots = solve_eq(coef.x, coef.y, coef.z);
	if (roots.n == 2)
		return (intersect_cylinder(ray, cy, roots.x1, roots.x2));
	return (intersect0());
}
