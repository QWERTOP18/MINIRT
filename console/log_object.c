/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:02:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 01:38:29 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	l0(void *data)
{
	const t_sphere	*sp = (const t_sphere *)data;

	log_vec("sphere", sp->center);
	printf("r:  %8.2f\n", sp->radius);
	log_material(sp->material);
}

void	l1(void *data)
{
	const t_plane	*pl = (const t_plane *)data;

	log_vec("plane normal", pl->normal);
	log_vec("plane center", pl->pos);
	log_material(pl->material);
}

void	l2(void *data)
{
	const t_cylinder	*cy = (const t_cylinder *)data;

	log_vec("cylinder normal", cy->normal);
	log_vec("cylinder center", cy->center);
	printf("r:  %8.2f,  h:  %8.2f\n", cy->radius, cy->height);
	log_material(cy->material);
}

void	l3(void *data)
{
	const t_cone	*cone = (const t_cone *)data;

	log_vec("cone normal", cone->normal);
	log_vec("cone vertex", cone->vertex);
	printf("r:  %8.2f,  h:  %8.2f\n", cone->radius, cone->height);
	log_material(cone->material);
}

void	l4(void *data)
{
	const t_triangle	*tr = (const t_triangle *)data;

	log_vec("triangle normal", tr->normal);
	log_material(tr->material);
}
