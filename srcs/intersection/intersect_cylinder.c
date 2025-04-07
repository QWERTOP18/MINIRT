/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 07:28:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* CYLINDER */
t_intersect	is2(t_unit_line ray, void *obj)
{
	t_intersect			is;
	const t_cylinder	*cy = (const t_cylinder *)obj;
	t_vec				ray_x_cynorm;
	t_vec				ray_x_cypos;
	t_vec				roots;

	is.dist = __DBL_MAX__;
	roots = solve_quadratic_eq(0, 0, 0);
	ray_x_cynorm = vec_cross(ray.dir, cy->normal);
	ray_x_cypos = vec_cross(ray.dir, vec_sub(ray.pos, cy->center));
	is.material = cy->material;
	return (is);
}
