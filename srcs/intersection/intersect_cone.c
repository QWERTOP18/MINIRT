/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 10:55:29 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static t_vec	intersect_cone(t_unit_line ray, const t_cone *cone)
{
	t_vec	roots;

	t_vec co; // 頂点からレイの原点へのベクトル
	t_vec v;  // ray.dir
	t_vec n;  // cone->normal
	double k; // tan(θ)^2
	double a, b, c;
	v = ray.dir;
	n = cone->normal;
	co = vec_sub(ray.pos, cone->center);
	k = pow(tan(cone->angle), 2);
	a = vec_dot(v, n) * vec_dot(v, n) - k * vec_dot(v, v);
	b = 2 * (vec_dot(v, n) * vec_dot(co, n) - k * vec_dot(v, co));
	c = vec_dot(co, n) * vec_dot(co, n) - k * vec_dot(co, co);
	roots = solve_eq(a, b, c);
	return (roots);
}

/* CONE */
t_intersect	is3(t_unit_line ray, void *obj)
{
	t_intersect		is;
	const t_cone	*cone = (const t_cone *)obj;
	t_vec			roots;
	t_pos_vec		p;
	double			hit_h;
	t_vec			v;
	t_vec			temp;
	double			k;

	k = pow(tan(cone->angle), 2);
	is.dist = __DBL_MAX__;
	roots = intersect_cone(ray, cone);
	if (roots.x == 0)
		return (is);
	// 手前の解（roots.y）を採用してみる（あとで裏返す）
	p = vec_add(ray.pos, vec_mul(ray.dir, roots.y));
	v = vec_sub(p, cone->center);
	hit_h = vec_dot(v, cone->normal);
	if (hit_h > 0 && hit_h < cone->height)
	{
		is.dist = roots.y;
		is.pos = p;
		// 接線ベクトルを使って法線を出す（簡略法）
		temp = vec_sub(v, vec_mul(cone->normal, hit_h * (1 + k)));
		is.normal = vec_normalize(temp);
		is.material = cone->material;
	}
	else
	{
		// 後ろ側も確認
		p = vec_add(ray.pos, vec_mul(ray.dir, roots.z));
		v = vec_sub(p, cone->center);
		hit_h = vec_dot(v, cone->normal);
		if (hit_h > 0 && hit_h < cone->height)
		{
			is.dist = roots.z;
			is.pos = p;
			temp = vec_sub(v, vec_mul(cone->normal, hit_h * (1 + k)));
			is.normal = vec_normalize(temp);
			is.material = cone->material;
		}
	}
	return (is);
}
