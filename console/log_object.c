/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:02:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 04:19:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	l0(void *data)
{
	const t_sphere	*sp = (const t_sphere *)data;

	log_vec("sphere", sp->center);
	printf("r:  %8.2f\n", sp->radius);
}

void	l1(void *data)
{
	const t_plane	*pl = (const t_plane *)data;

	log_vec("plane normal", pl->normal);
	log_vec("plane center", pl->pos);
}

void	l2(void *data)
{
	const t_cylinder	*cy = (const t_cylinder *)data;

	log_vec("cylinder normal", cy->normal);
	log_vec("cylinder center", cy->center);
	printf("r:  %8.2f,  h:  %8.2f\n", cy->radius, cy->height);
}

void	l3(void *data)
{
	(void)data;
}

void	log_obj(t_list *obj)
{
	static console_log	l[] = {l0, l1, l2, l3};

	if (!obj)
	{
		printf(RED "object None" RESET "\n");
		return ;
	}
	l[obj->type](obj->data);
	printf("\n");
}
