/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/15 18:05:20 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static int	tr_check_a(const t_tr_elements *te)
{
	return (fabs(te->a) >= FT_EPSILON);
}

static int	tr_check_uv(const t_tr_elements *te)
{
	return (te->u >= 0.0 && te->u <= 1.0 && te->v >= 0.0 && te->u
		+ te->v <= 1.0);
}

static int	tr_calculate_elements(t_tr_elements *te, t_unit_line ray,
		const t_triangle *tr)
{
	te->e1 = vec_sub(tr->p1, tr->p0);
	te->e2 = vec_sub(tr->p2, tr->p0);
	te->h = vec_cross(ray.dir, te->e2);
	te->a = vec_dot(te->e1, te->h);
	if (!tr_check_a(te))
		return (0);
	te->f = 1.0 / te->a;
	te->s = vec_sub(ray.pos, tr->p0);
	te->u = te->f * vec_dot(te->s, te->h);
	te->q = vec_cross(te->s, te->e1);
	te->v = te->f * vec_dot(ray.dir, te->q);
	te->t = te->f * vec_dot(te->e2, te->q);
	return (tr_check_uv(te) && te->t >= FT_EPSILON);
}

static void	tr_set_result(t_intersect *is, t_unit_line ray,
		const t_triangle *tr, const t_tr_elements *te)
{
	is->dist = te->t;
	is->pos = vec_add(ray.pos, vec_mul(ray.dir, te->t));
	is->normal = tr->normal;
	if (vec_dot(is->normal, ray.dir) > 0)
		is->normal = vec_mul(is->normal, -1);
}

t_intersect	is4(t_unit_line ray, void *obj)
{
	const t_triangle	*tr = (const t_triangle *)obj;
	t_intersect			is;
	t_tr_elements		te;

	is.dist = __DBL_MAX__;
	is.material = tr->material;
	if (!tr_calculate_elements(&te, ray, tr))
		return (is);
	tr_set_result(&is, ray, tr, &te);
	return (is);
}
