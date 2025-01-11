/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 10:48:36 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*update(t_sys *sys)
{
	int	id;

	id = sys->obj->id_of_camera;
	render_img(sys->obj->camera[id], sys); //実際には最初しか計算していないので名前を変えるか
	return (sys->obj->camera[id]->img->img);
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