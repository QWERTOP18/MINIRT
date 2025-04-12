/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_eq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 07:23:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 07:34:27 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_roots	solve_linear_eq(double b, double c)
{
	t_roots	roots;

	ft_memset(&roots, 0, sizeof(roots));
	if (fabs(b) < FT_EPSILON)
	{
		if (fabs(c) < FT_EPSILON)
			roots.n = -1;
		else
			roots.n = 0;
	}
	else
	{
		roots.n = 1;
		roots.x1 = -c / b;
		roots.x2 = -c / b;
	}
	return (roots);
}

// ax² + bx + c = 0
t_roots	solve_quadratic_eq(double a, double b, double c)
{
	t_roots	roots;
	double	d;

	ft_memset(&roots, 0, sizeof(roots));
	d = b * b - 4 * a * c;
	if (d < -FT_EPSILON)
		roots.n = 0;
	else if (fabs(d) < FT_EPSILON)
	{
		roots.n = 1;
		roots.x1 = -b / (2 * a);
		roots.x2 = -b / (2 * a);
	}
	else
	{
		roots.x1 = (-b - sqrt(d)) / (2 * a);
		roots.x2 = (-b + sqrt(d)) / (2 * a);
		roots.n = 2;
	}
	return (roots);
}

t_roots	solve_eq(double a, double b, double c)
{
	if (fabs(a) < FT_EPSILON)
		return (solve_linear_eq(b, c));
	else
		return (solve_quadratic_eq(a, b, c));
}
