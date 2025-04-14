/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 10:13:53 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "screen.h"

int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	int	id;

	id = sys->obj->id_of_camera;
	if (button == LEFT_CLICK)
	{
		log_pixel(sys->obj->camera[id]->img->pixels, y, x);
	}
	if (button == RIGHT_CLICK)
	{
		log_pixel_detail(sys->obj->camera[id]->img->pixels, y, x);
	}
	if (button == CENTER_CLICK)
	{
		log_objs_detail(sys->obj);
	}
	return (0);
}

int	key_handler2(int key, t_sys *sys)
{
	int	n_camera;

	n_camera = sys->obj->num_of_camera;
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
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	int	n_light;

	n_light = sys->obj->num_of_light;
	if (key == ESCAPE)
		exit_handler(sys);
	if (key == UP || key == DOWN)
		key_handler2(key, sys);
	if (key == 'i')
		log_objs_detail(sys->obj);
	if (0 <= key - '0' && key - '0' < n_light)
	{
		sys->obj->light[key - '0']->ison ^= 1;
		log_light(sys->obj->light, n_light);
		sys->obj->camera[sys->obj->id_of_camera]->isupdate = True;
	}
	return (0);
}
// if (key == 'i')
// 	log_objs(sys->obj);

int	exit_handler(t_sys *sys)
{
	system_exit(sys, 0);
	return (0);
}
