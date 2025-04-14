/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:00:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 12:37:28 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include "screen.h"
#include "system.h"

void	system_exit(t_sys *sys, int status)
{
	if (!sys)
		return (exit(status));
	if (!sys->obj)
		return (free(sys), exit(status));
	camera_deinit(sys->mlx, sys->obj->camera, sys->obj->num_of_camera);
	light_deinit(sys->obj->light, sys->obj->num_of_light);
	objs_deinit(sys->obj);
	if (!sys->mlx)
		return (free(sys), exit(status));
	mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	mlx_loop_end(sys->mlx);
	free(sys->mlx);
	return (free(sys), exit(status));
}

t_objects	*init_objs(void)
{
	t_objects	*objs;

	objs = malloc(sizeof(t_objects));
	if (!objs)
	{
		perror("Error: Allocation failed for t_objects");
		return (NULL);
	}
	objs->num_of_camera = 0;
	objs->id_of_camera = 0;
	objs->num_of_light = 0;
	objs->objs = NULL;
	objs->ambient = vec(-1, -1, -1);
	return (objs);
}

t_sys	*system_init(void)
{
	t_sys	*sys;

	sys = xcalloc(1, sizeof(t_sys), NULL);
	sys->width = 1024;
	sys->height = 1024;
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	return (sys);
}

void	*xcalloc(size_t nmemb, size_t size, t_sys *sys)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		system_exit(sys, E_ALLOCATE);
	return (ptr);
}
