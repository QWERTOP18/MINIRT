/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 09:01:28 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*update(t_sys *sys)
{
	int	id;

	id = sys->obj->id_of_camera;
	// if loading return sys->img.img
	return (sys->obj->camera[id].img.img);
}

int	loop_handler(t_sys *sys)
{
	void	*img;

	img = update(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, img, 0, 0);
	return (0);
}

void	setup_hook(t_sys *sys)
{
	mlx_hook(sys->win, KeyPress, KeyPressMask, key_handler, sys);
	mlx_hook(sys->win, ClientMessage, StructureNotifyMask, exit_handler, sys);
	mlx_mouse_hook(sys->win, mouse_handler, sys);
	mlx_loop_hook(sys->mlx, loop_handler, sys);
}

int	main(int argc, char **argv)
{
	t_sys	*sys;

	if (argc != 2)
		system_exit(NULL, E_INVALID_INPUT);
	sys = system_init();
	sys->obj = parse_file(argv[1], sys);
	setup_hook(sys);
	mlx_loop(sys->mlx);
	system_exit(sys, 0);
}

/*

* main
* system init
* parse
* setup hook



*/