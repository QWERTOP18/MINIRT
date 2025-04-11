/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 07:33:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* SQUARE */
t_intersect	is0(t_unit_line ray, void *obj)
{
	t_intersect		is;
	t_vec			camera_center;
	t_vec			coef;
	t_roots			roots;
	const t_sphere	*sp = (const t_sphere *)obj;

	is.dist = __DBL_MAX__;
	camera_center = vec_sub(ray.pos, sp->center);
	coef.y = 2 * vec_dot(ray.dir, camera_center);
	coef.z = vec_dot(camera_center, camera_center) - sp->radius;
	roots = solve_eq(1, coef.y, coef.z);
	if (roots.n < 1)
		return (is);
	is.dist = roots.x1;
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, is.dist));
	is.normal = vec_normalize(vec_sub(is.pos, sp->center));
	is.material = sp->material;
	return (is);
}
