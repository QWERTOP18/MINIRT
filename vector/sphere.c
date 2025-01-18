/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:15:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/18 18:00:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_sphere	*sphere_new(t_pos_vec center, double radius, void *material)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	sphere->material = material;
	return (sphere);
}

double	sphere_distance(t_sphere s, t_vec p)
{
	return (vec_magnitude(vec_sub(s.center, p)) - s.radius);
}
