/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:15:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 05:46:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_sphere	*sphere_new(t_pos_vec center, double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

double	sphere_distance(t_sphere s, t_vec p)
{
	return (vec_magnitude(vec_sub(s.center, p)) - s.radius);
}