/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 04:58:39 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	intersect_cylinder(t_unit_line ray, t_cylinder *cy, double outer,
		double inner)
{
	t_intersect	is;
	t_pos_vec	outer_pos;
	t_pos_vec	inner_pos;
	t_vec		center_outer;
	t_vec		center_inner;
	double		inner_h;

	outer_pos = vec_add(ray.pos, vec_mul(ray.dir, outer));
	inner_pos = vec_add(ray.pos, vec_mul(ray.dir, inner));
	center_outer = vec_sub(outer_pos, cy->center);
	center_inner = vec_sub(inner_pos, cy->center);
	is.material = cy->material;
	inner_h = vec_dot(center_inner, cy->normal);
	is.dist = inner;
	is.normal = vec_normalize(vec_sub(vec_mul(cy->normal, inner_h),
				center_inner));
	return (is);
}

/* CYLINDER */
t_intersect	is2(t_unit_line ray, void *obj)
{
	t_intersect			is;
	const t_cylinder	*cy = (const t_cylinder *)obj;
	t_vec				ray_x_cynorm;
	t_vec				ray_x_cypos;
	double				b;
	double				c;
	double				a;
	t_vec				roots;

	is.dist = __DBL_MAX__;
	ray_x_cynorm = vec_cross(ray.dir, cy->normal);
	ray_x_cypos = vec_cross(ray.dir, vec_sub(ray.pos, cy->center));
	b = 2 * vec_dot(ray_x_cynorm, ray_x_cypos);
	c = pow(vec_magnitude(ray_x_cypos), 2) - pow(cy->radius, 2);
	a = pow(vec_magnitude(ray_x_cynorm), 2);
	// roots = solve_quadratic_eq(a, b, c);
	if (roots.x <= 1)
		return (is);
	return (intersect_cylinder(ray, cy, roots.z, roots.y));
}

// 底面から交点までの高さ
// double		height_outer = vec3_dot(center2p_outer, cylinder.normal);
// double		height_inner = vec3_dot(center2p_inner, cylinder.normal);

// if (height_outer >= 0 && height_outer <= cylinder.height)
// {
// 	intersection.has_intersection = true;
// 	intersection.normal = vec3_normalize(vec3_sub(center2p_outer,
// 				vec3_mult(cylinder.normal, height_outer)));
// 	intersection.distance = t_outer;
// 	intersection.position = p_outer;
// }
// else if (height_inner >= 0 && height_inner <= cylinder.height)
// {
// 	intersection.has_intersection = true;
// 	intersection.normal = vec3_normalize(vec3_sub(vec3_mult(cylinder.normal,
// 					height_inner), center2p_inner));
// 	intersection.distance = t_inner;
// 	intersection.position = p_inner;
// }
// else
// {
// 	intersection.has_intersection = false;
// }
// return (intersection);