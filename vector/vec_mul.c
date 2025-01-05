/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:23:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 03:25:27 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_mul(t_vec v, double scalar)
{
	t_vec	v_scaled;

	v_scaled.x = v.x * scalar;
	v_scaled.y = v.y * scalar;
	v_scaled.z = v.z * scalar;
	return (v_scaled);
}
