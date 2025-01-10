/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:24:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 14:59:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"
#include "mlx_handler.h"

t_camera	*camera_init(t_vec center, t_vec orient, int fov, t_sys *sys)
{
	t_camera	*camera;

	LOG;
	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		system_exit(sys, E_ALLOCATE);
	camera->pos = center;
	camera->dir = vec_normalize(orient);
	camera->fov = fov / 180 * M_PI;
	camera->dist_to_screen = sys->width / 2 / tan(fov / 2);
	printf("dist to screen %f\n", camera->dist_to_screen);
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