/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/18 14:09:57 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

// typedef struct s_plane
// {
// 	t_unit_vec	wdir;
// 	t_unit_vec	hdir;
// 	t_unit_vec	normal;
// 	t_pos_vec	pos;
// 	double		width;
// 	double		height;
// 	void		*material;
// }				t_plane;

t_intersect	is1(t_unit_line ray, void *obj)
{
	t_intersect		is;
	t_vec			plane_vec;
	const t_plane	*pl = (const t_plane *)obj;

	is.dist = __DBL_MAX__;
	plane_vec = vec_sub(ray.pos, pl->pos);
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	return (is);
}

// t_intersection	calc_plane_intersection(t_ray ray, t_object plane)
// {
// 	double		d_n_dot;
// 	t_vec3		center2camera;
// 	double		t;
// 	t_intersection intersection;

// 	center2camera = vec3_sub(ray.start, plane.center);
// 	d_n_dot = vec3_dot(vec3_mult(ray.direction, -1), plane.normal);
// 	if (d_n_dot == 0)
// 	{
// 		intersection.has_intersection = false;
// 		return (intersection);
// 	}
// 	t = vec3_dot(center2camera, plane.normal) / d_n_dot;
// 	intersection.has_intersection = true;
// 	intersection.distance = t;
// 	// d_n_dot(cosθ)がマイナスだったらなす角が90°より大きいから法線ベクトルを逆向きになる
// 	intersection.normal = d_n_dot > 0 ? plane.normal : vec3_mult(plane.normal,//-1);
// 	intersection.position = vec3_add(ray.start, vec3_mult(ray.direction,
//				t));

// 	return (intersection);
// }
