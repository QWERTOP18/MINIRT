/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 07:03:39 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/**
 *
 * @return x:  number of root
 * @return y:  smaller root
 * @return z:  larger root
 */
t_vec	solve_quadratic_eq(double a, double b, double c)
{
	double	discriminant;
	t_vec	roots;

	roots = vec(0, 0, 0);
	discriminant = b * b - 4 * a * c;
	if (discriminant < FT_EPSILON)
	{
		roots.x = 0;
	}
	else if (discriminant == 0)
	{
		roots.x = 1;
	}
	return (roots);
}

t_intersect	intersect_dispatcher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3};

	return (isfunc[obj->type](ray, obj->data));
}
