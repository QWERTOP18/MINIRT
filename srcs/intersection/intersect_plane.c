/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 07:27:51 by ymizukam         ###   ########.fr       */
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

/* PLANE */
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
	// is.dist = vec_magnitude(vec_sub(ray.pos, pl->pos));
	is.dist = vec_dot(vec_sub(ray.pos, pl->pos), pl->normal) / normal_dot_ray;
	is.normal = pl->normal; // todo consider directions
	is.pos = vec_add(ray.pos, vec_mul(ray.dir, is.dist));
	is.material = pl->material;
	return (is);
}
