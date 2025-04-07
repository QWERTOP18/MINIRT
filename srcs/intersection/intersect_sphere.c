/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 07:27:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/* SQUARE */
t_intersect	is0(t_unit_line ray, void *obj)
{
	t_intersect		is;
	t_vec			camera_center;
	double			b;
	double			c;
	const t_sphere	*sp = (const t_sphere *)obj;

	camera_center = vec_sub(ray.pos, sp->center);
	b = 2 * vec_dot(ray.dir, camera_center);
	c = vec_dot(camera_center, camera_center) - sp->radius;
	if (b * b - 4 * 1 * c < 0)
		is.dist = __DBL_MAX__;
	// is.normal = vec(0, 0, 0);
	// is.pos = vec(0, 0, 0);
	else
	{
		is.dist = (-b - sqrt(b * b - 4 * 1 * c)) / 2;
		is.pos = vec_add(ray.pos, vec_mul(ray.dir, is.dist));
		is.normal = vec_normalize(vec_sub(is.pos, sp->center));
	}
	is.material = sp->material;
	return (is);
}
