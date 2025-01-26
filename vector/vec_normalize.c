/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:24:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/20 10:54:25 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double	vec_magnitude(t_vec v)
{
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (magnitude);
}

t_unit_vec	vec_normalize(t_vec v)
{
	double	magnitude;
	t_vec	v_normalized;

	magnitude = vec_magnitude(v);
	if (magnitude == 0.0)
		return (v);
	v_normalized.x = v.x / magnitude;
	v_normalized.y = v.y / magnitude;
	v_normalized.z = v.z / magnitude;
	return (v_normalized);
}
