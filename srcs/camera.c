/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:24:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 11:22:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "mlx_handler.h"

t_camera	*camera_init(t_vec center, t_vec orient, double fov, t_sys *sys)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		system_exit(sys, E_ALLOCATE);
	camera->pos = center;
	camera->dir = orient;
	camera->fov = fov;
	camera->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	if (!camera->img.img)
		system_exit(NULL, E_ALLOCATE);
	camera->img.addr = mlx_get_data_addr(camera->img.img,
			&camera->img.bits_per_pixel, &camera->img.line_length,
			&camera->img.endian);
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