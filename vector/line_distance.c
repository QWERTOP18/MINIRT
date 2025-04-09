/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:34:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 04:16:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// double	line_distance(t_line l, t_pos_vec p)
// {
// 	return (0);
// }
double	vec_distance(t_vec v1, t_vec v2)
{
	t_vec	diff;

	diff = vec_sub(v1, v2);
	return (vec_magnitude(diff));
}
