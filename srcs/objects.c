/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:24 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 11:25:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	objs_deinit(void *mlx, t_objects *objs)
{
	if (!objs)
		return ;
	//
	ft_lstclear(&objs->objs, free);
	// light
	// cameradeinit はsystemにまわしたほうがいいかもしれない
	camera_deinit(mlx, objs->camera, objs->num_of_camera);
}