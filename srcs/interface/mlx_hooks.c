/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/27 09:34:06 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "screen.h"

int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	int	id;

	printf("mouse %d\n", button);
	id = sys->obj->id_of_camera;
	if (button == LEFT_CLICK)
	{
		log_pixel(sys->obj->camera[id]->img->pixels, y, x);
	}
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	int	n_camera;
	int	n_light;

	// printf("key: %d\n", key);
	n_camera = sys->obj->num_of_camera;
	n_light = sys->obj->num_of_light;
	if (key == ESCAPE)
		exit_handler(sys);
	if (key == UP)
	{
		sys->obj->id_of_camera++;
		sys->obj->id_of_camera %= n_camera;
	}
	if (key == DOWN)
	{
		sys->obj->id_of_camera--;
		sys->obj->id_of_camera += n_camera;
		sys->obj->id_of_camera %= n_camera;
	}
	if (0 <= key - '0' && key - '0' < n_light)
	{
		sys->obj->light[key - '0']->ison ^= 1;
		// printf("light no.%d is swithed\n", key - '0');
		log_light(sys->obj->light, n_light);
	}
	// if (0 <= key - '0' && key - '0' < n_camera)
	// 	sys->obj->id_of_camera = key - '0';
	// printf("camera id %d\n", sys->obj->id_of_camera);
	if (key == 'i')
		log_objs(sys->obj);
	return (0);
}

int	exit_handler(t_sys *sys)
{
	LOG;
	// mlx_destroy_image(sys->mlx, sys->img.img);
	system_exit(sys, 0);
	return (0);
}
