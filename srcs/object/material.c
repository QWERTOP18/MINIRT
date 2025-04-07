/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 05:45:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 05:55:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	*material_init(t_vec color)
{
	t_material	*material;

	material = ft_calloc(1, sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = color_scaler(color);
	return (material);
}
