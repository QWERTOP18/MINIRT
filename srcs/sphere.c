/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:54:28 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 05:40:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

t_list	*sphere_init(t_vec center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->radius = radius;
	return (ft_lstnew(SPHERE, sphere));
}

int	line_intersects_sphere(t_unit_line line, t_sphere sphere)
{
	t_vec	oc;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub(line.pos, sphere.center);
	// a is always 1
	// double a = vec_dot(line.dir, line.dir);
	b = 2 * vec_dot(oc, line.dir);
	c = vec_dot(oc, oc) - (sphere.radius * sphere.radius);
	discriminant = b * b - 4 * c;
	if (discriminant < 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
