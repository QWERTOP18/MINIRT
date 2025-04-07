/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:33:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/20 10:56:16 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255
// id pos normal color

t_plane	*plane_new(t_pos_vec pos, t_vec normal, void *material)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->pos = pos;
	plane->normal = vec_normalize(normal);
	plane->material = material;
	return (plane);
}
