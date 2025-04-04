/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:09 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*update(t_sys *sys)
{
	int			id;
	t_camera	*camera;

	id = sys->obj->id_of_camera;
	camera = sys->obj->camera[id];
	if (camera->isupdate == True)
		render_img(camera, sys); //実際には最初しか計算していないので名前を変えるか
	return (camera->img->img);
}

int	loop_handler(t_sys *sys)
{
	void	*img;

	img = update(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sys	*sys;

	LOG;
	if (argc != 2)
		system_exit(NULL, E_INVALID_INPUT);
	sys = system_init();
	sys->obj = parse_file(argv[1], sys);
	setup_mlx(sys);
	LOG;
	mlx_loop(sys->mlx);
	system_exit(sys, 0);
}

/*

* main
* system init
* parse
* setup hook



*/