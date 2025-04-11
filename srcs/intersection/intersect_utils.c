/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 06:38:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/**
 *
 * @return x:  number of root
 * @return y:  smaller root
 * @return z:  larger root
 */
// 一次方程式 bx + c = 0
t_vec	solve_linear_eq(double b, double c)
{
	t_vec	roots;

	roots = vec(0, 0, 0);
	if (fabs(b) < FT_EPSILON)
	{
		if (fabs(c) < FT_EPSILON)
			roots.x = -1; // 無限解
		else
			roots.x = 0; // 解なし
	}
	else
	{
		roots.x = 1;
		roots.y = -c / b;
	}
	return (roots);
}

// 二次方程式 ax² + bx + c = 0
t_vec	solve_quadratic_eq(double a, double b, double c)
{
	t_vec	roots;
	double	discriminant;

	roots = vec(0, 0, 0);
	discriminant = b * b - 4 * a * c;
	if (discriminant < -FT_EPSILON)
	{
		roots.x = 0; // 実数解なし
	}
	else if (fabs(discriminant) < FT_EPSILON)
	{
		roots.x = 1;
		roots.y = -b / (2 * a);
		roots.z = -b / (2 * a);
	}
	else
	{
		roots.x = 2;
		roots.y = (-b - sqrt(discriminant)) / (2 * a);
		roots.z = (-b + sqrt(discriminant)) / (2 * a);
	}
	return (roots);
}

/**
 *
 * @return x:  number of root
 * @return y:  smaller root
 * @return z:  larger root
 */
t_vec	solve_eq(double a, double b, double c)
{
	if (fabs(a) < FT_EPSILON)
		return (solve_linear_eq(b, c));
	else
		return (solve_quadratic_eq(a, b, c));
}

t_intersect	intersect_dispatcher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3, is4, is5, is6, is7};

	return (isfunc[obj->type](ray, obj->data));
}
