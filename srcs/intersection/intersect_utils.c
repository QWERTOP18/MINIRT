/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 15:45:58 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	intersect_dispatcher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3, is4, is5, is6, is7};

	return (isfunc[obj->type](ray, obj->data));
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
	t_intersect	is;

	(void)ray;
	(void)obj;
	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	is.material = NULL;
	return (is);
}
