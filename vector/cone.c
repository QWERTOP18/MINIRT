/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:40:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 11:10:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @param angles.x angle  angles.y height
 */
t_cone	*cone_new(t_pos_vec center, t_vec normal, t_vec angles, void *material)
{
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	if (!cone)
		return (NULL);
	cone->center = center;
	cone->angle = angles.x * M_PI / 180;
	cone->height = angles.y; // angles.y に高さ
	cone->normal = normal;
	cone->material = material;
	cone->radius = cone->height * tan(cone->angle);
	return (cone);
}
void	cone_clear(t_cone *cone)
{
	if (!cone)
		return ;
	free(cone->material);
	free(cone);
}
