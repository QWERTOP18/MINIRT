/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:00:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 21:09:56 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx_handler.h"
#include "parse.h"
#include "system.h"

void	system_exit(t_sys *sys, int status)
{
	LOG;
	if (status == E_INVALID_INPUT)
	{
		// ft_putstr_fd(ERRMSG1, 2);
		// ft_putstr_fd(ERRMSG2, 2);
	}
	if (!sys)
		return (free(sys), exit(status));
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

t_sys	*system_init(void)
{
	t_sys	*sys;

	LOG;
	sys = xcalloc(1, sizeof(t_sys), NULL);
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	return (sys);
}
void	*xcalloc(size_t nmemb, size_t size, t_sys *sys)
{
	void *ptr = ft_calloc(nmemb, size);
	if (!ptr)
		system_exit(sys, E_ALLOCATE);
	return (ptr);
}