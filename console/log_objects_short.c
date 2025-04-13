/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_objects_short.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:49:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 02:08:12 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	ls0(void *data)
{
	const t_sphere	*sp = (const t_sphere *)data;

	printf(UNDERLINE BLUE BOLD "sphere" RESET "\n");
	log_vec_inline("center", sp->center);
	printf("r:  %8.2f\n", sp->radius);
	log_material_inline(sp->material);
}

void	ls1(void *data)
{
	const t_plane	*pl = (const t_plane *)data;

	printf(UNDERLINE BLUE BOLD "plane" RESET "\n");
	log_vec_inline("normal", pl->normal);
	log_vec_inline("center", pl->pos);
	log_material_inline(pl->material);
}

void	ls2(void *data)
{
	const t_cylinder	*cy = (const t_cylinder *)data;

	printf(UNDERLINE BLUE BOLD "cylinder" RESET "\n");
	log_vec_inline("normal", cy->normal);
	log_vec_inline("center", cy->center);
	printf("r:  %8.2f,  h:  %8.2f\n", cy->radius, cy->height);
	log_material_inline(cy->material);
}

void	ls3(void *data)
{
	const t_cone	*cone = (const t_cone *)data;

	printf(UNDERLINE BLUE BOLD "cone" RESET "\n");
	log_vec_inline("normal", cone->normal);
	log_vec_inline("vertex", cone->vertex);
	printf("r:  %8.2f,  h:  %8.2f\n", cone->radius, cone->height);
	log_material_inline(cone->material);
}

void	ls4(void *data)
{
	const t_triangle	*tr = (const t_triangle *)data;

	printf(UNDERLINE BLUE BOLD "triangle" RESET "\n");
	log_vec_inline("normal", tr->normal);
	log_material_inline(tr->material);
}
