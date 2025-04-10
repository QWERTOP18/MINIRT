/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 10:34:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	is4(t_unit_line ray, void *obj)
{
	t_intersect	is;

	(void)ray;
	(void)obj;
	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	is.material = NULL;
	return (is);
}
t_intersect	is5(t_unit_line ray, void *obj)
{
	t_intersect	is;

	(void)ray;
	(void)obj;
	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	is.material = NULL;
	return (is);
}

t_intersect	is6(t_unit_line ray, void *obj)
{
	t_intersect	is;

	(void)ray;
	(void)obj;
	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	is.material = NULL;
	return (is);
}

t_intersect	is7(t_unit_line ray, void *obj)
{
	t_intersect is;

	(void)ray;
	(void)obj;
	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	is.material = NULL;
	return (is);
}