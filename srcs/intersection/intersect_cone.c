/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 07:31:40 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect		intersect_cone(t_unit_line ray, const t_cone *cone, double t1,
					double t2);

static t_vec	get_cone_dv_parts(t_vec dir, t_vec v, double *dv_out)
{
	*dv_out = vec_dot(dir, v);
	return (vec_sub(dir, vec_mul(v, *dv_out)));
}

static t_vec	get_cone_cov_parts(t_vec co, t_vec v, double *cov_out)
{
	*cov_out = vec_dot(co, v);
	return (vec_sub(co, vec_mul(v, *cov_out)));
}

static t_vec	get_cone_coeffs(t_vec d_mv, t_vec co_mv, t_cone_vars *vars)
{
	t_vec	coef;

	coef.x = vec_dot(d_mv, d_mv) - vars->k * vars->k * vars->dv * vars->dv;
	coef.y = 2 * (vec_dot(d_mv, co_mv) - vars->k * vars->k * vars->dv
			* vars->cov);
	coef.z = vec_dot(co_mv, co_mv) - vars->k * vars->k * vars->cov * vars->cov;
	return (coef);
}

/* CONE */
t_intersect	is3(t_unit_line ray, void *obj)
{
	const t_cone	*cone;
	t_cone_vars		vars;
	t_vec			coef;
	t_roots			roots;

	cone = (const t_cone *)obj;
	vars.v = cone->normal;
	vars.co = vec_sub(ray.pos, cone->vertex);
	vars.k = tan(cone->angle);
	coef = get_cone_coeffs(get_cone_dv_parts(ray.dir, vars.v, &vars.dv),
			get_cone_cov_parts(vars.co, vars.v, &vars.cov), &vars);
	roots = solve_eq(coef.x, coef.y, coef.z);
	if (roots.n == 2)
		return (intersect_cone(ray, cone, roots.x1, roots.x2));
	return (intersect0());
}
