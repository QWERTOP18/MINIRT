/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:24 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 06:13:16 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	obj_clear(void *data, int type)
{
	if (type == SPHERE)
		sphere_clear(data);
	if (type == PLANE)
		plane_clear(data);
	if (type == CYLINDER)
		cylinder_clear(data);
	// if (type==)
}

void	objs_deinit(t_objects *objs)
{
	LOG;
	if (!objs)
		return ;
	ft_lstclear(&objs->objs, obj_clear);
	free(objs);
}
