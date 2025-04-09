/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:46:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/09 22:47:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// cy -5,-1,0   0,1,0   4  2 0,255,0
// id center dir diameter  hight   color

/**
 * @param lengths x->radius y->height
 */
t_cylinder	*cylinder_new(t_pos_vec center, t_vec normal, t_vec lengths,
		void *material)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->center = center;
	cylinder->radius = lengths.x;
	cylinder->height = lengths.y;
	cylinder->material = material;
	return (cylinder);
}

void	cylinder_clear(t_cylinder *cy)
{
	if (!cy)
		return ;

	free(cy->material);
	free(cy);
}