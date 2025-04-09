/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 02:14:20 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* CYLINDER */
t_intersect	is2(t_unit_line ray, void *obj)
{
	t_intersect is;
	const t_cylinder *cy = (const t_cylinder *)obj;
	t_vec ray_x_cynorm;
	t_vec ray_x_cypos;
	double b;
	double c;
	double a;

	is.dist = __DBL_MAX__;
	ray_x_cynorm = vec_cross(ray.dir, cy->normal);
	ray_x_cypos = vec_cross(ray.dir, vec_sub(ray.pos, cy->center));
	b = 2 * vec_dot(ray_x_cynorm, ray_x_cypos);
	c = pow(vec_magnitude(ray_x_cypos), 2) - pow(cy->radius, 2);
	// t_vec roots = solve_quadratic_eq(0, 0, 0);
	a = pow(vec_magnitude(ray_x_cynorm), 2);

	if (b * b - 4 * a * c < 0)
		is.dist = __DBL_MAX__;
	// else
	// {
	// 	is.dist = (-b - sqrt(b * b - 4 * a * c)) / 2;
	// 	is.pos = vec(0, 0, 0);
	// 	is.normal = vec(1, 1, 1);
	// }
	is.material = cy->material;
	return (is);
}