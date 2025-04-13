/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:45:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 04:42:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "object.h"

t_material	*material_init(t_vec color)
{
	t_material	*material;

	material = ft_calloc(1, sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = color_scaler(color);
	material->gloss = 40;
	material->k_specular = 0.9;
	material->k_diffuse = 0.9;
	return (material);
}

t_material	*material_init_l(t_vec color, int line)
{
	t_material	*material;

	material = material_init(color);
	material->line = line;
	return (material);
}

/**
 * @param coef x:gloss y: k_specular z:k_diffuse
 */
t_material	*material_init_with_param(t_vec color, t_vec coef, int line)
{
	t_material	*material;

	material = ft_calloc(1, sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = color_scaler(color);
	material->gloss = coef.x;
	material->k_specular = coef.y;
	material->k_diffuse = coef.z;
	material->line = line;
	return (material);
}

t_material	*get_material(t_list *list)
{
	if (list->type == SPHERE)
		return (((t_sphere *)list->data)->material);
	if (list->type == PLANE)
		return (((t_plane *)list->data)->material);
	if (list->type == CYLINDER)
		return (((t_cylinder *)list->data)->material);
	return (NULL);
}
