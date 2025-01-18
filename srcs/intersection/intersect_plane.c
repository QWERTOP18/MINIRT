/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/18 21:09:30 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "minirt.h"

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
	const t_plane	*pl = (const t_plane *)obj;
	double			normal_dot_ray;

	is.dist = __DBL_MAX__;
	normal_dot_ray = vec_dot(pl->normal, ray.dir);
	if (normal_dot_ray <= FT_EPSILON)
	{
		return (is);
	}
	is.dist = vec_magnitude(vec_sub(ray.pos, pl->pos));
	is.normal = pl->normal; // todo consider directions
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, is.dist));
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
