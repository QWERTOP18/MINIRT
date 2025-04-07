/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:24:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 00:04:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"
#include "screen.h"

t_rect	set_screen(t_camera *c, t_sys *sys)
{
	int		dist;
	t_rect	screen;

	LOG;
	dist = sys->width / 2 / tan(c->fov / 2);
	screen.normal = c->dir;
	screen.pos = vec_add(vec_mul(c->dir, dist), c->pos);
	screen.wdir = vec_normalize(vec(-c->dir.z, 0, c->dir.x));
	screen.hdir = vec_cross(screen.normal, screen.wdir);
	log_vec("screen center", screen.pos);
	log_vec("screen normal", screen.normal);
	return (screen);
}

t_camera	*camera_init(t_vec pos, t_vec orient, int fov, t_sys *sys)
{
	t_camera	*camera;

	LOG;
	camera = xcalloc(1, sizeof(t_camera), sys);
	camera->img = xcalloc(1, sizeof(t_screen), sys);
	camera->pos = pos;
	camera->dir = vec_normalize(orient);
	camera->fov = (double)fov / 180 * M_PI;
	camera->screen = set_screen(camera, sys);
	setup_img(camera->img, sys);
	camera->isupdate = True;
	return (camera);
}

void	camera_deinit(void *mlx, t_camera *camera[], int size)
{
	int	i;

	LOG;
	i = 0;
	if (!camera)
		return ;
	while (i < size)
	{
		mlx_destroy_image(mlx, camera[i]->img->img);
		pixels_deinit(camera[i]->img->height, camera[i]->img->width,
			camera[i]->img->pixels);
		free(camera[i]->img);
		free(camera[i]);
		i++;
	}
}
