/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:45:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 06:42:13 by ymizukam         ###   ########.fr       */
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
	material->gloss = 800;
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