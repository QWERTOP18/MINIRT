/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:24:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 15:39:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"
#include "mlx_handler.h"

t_rect	set_screen(t_camera *c, t_sys *sys)
{
	int		dist;
	t_rect	screen;

	screen.normal = c->dir;
	dist = sys->width / 2 / tan(c->fov / 2);
	screen.pos = vec_add(vec_mul(c->dir, dist), c->pos);
	log_vec(screen.pos);
	return (screen);
}

t_camera	*camera_init(t_vec pos, t_vec orient, int fov, t_sys *sys)
{
	t_camera	*camera;

	LOG;
	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		system_exit(sys, E_ALLOCATE);
	camera->pos = pos;
	camera->dir = vec_normalize(orient);
	camera->fov = fov / 180 * M_PI;
	camera->screen = set_screen(camera, sys);
	setup_img(&camera->img, sys);
	return (camera);
}

void	camera_deinit(void *mlx, t_camera camera[], int size)
{
	int i = 0;
	while (i < size)
	{
		mlx_destroy_image(mlx, camera[i].img.img);
		i++;
	}
}