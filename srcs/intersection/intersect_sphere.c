/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 15:52:08 by ymizukam         ###   ########.fr       */
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
	coef.z = vec_dot(camera_center, camera_center) - pow(sp->radius, 2);
	roots = solve_eq(1, coef.y, coef.z);
	if (roots.n == 0)
		return (is);
	if (roots.x1 > 0)
		is.dist = roots.x1;
	else if (roots.x2 > 0)
		is.dist = roots.x2;
	else
		return (is);
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, is.dist));
	is.normal = vec_normalize(vec_sub(is.pos, sp->center));
	// 球の内部にあるときは法線ベクトルを反転
	if (roots.x1 * roots.x2 < 0)
		is.normal = vec_mul(is.normal, -1);
	is.material = sp->material;
	return (is);
}
