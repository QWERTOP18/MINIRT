/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/13 15:29:45 by aryamamo         ###   ########.fr       */
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
		render_img(camera, sys);
	return (camera->img->img);
}

int	loop_handler(t_sys *sys)
{
	void	*img;

	img = update(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, img, 0, 0);
	return (0);
}

/* --- main() --- */
int	main(int argc, char **argv)
{
	t_sys	*sys;

	LOG;
	if (argc != 2)
		system_exit(NULL, E_INVALID_INPUT);
	sys = system_init();
	// #ifdef GEN
	sys->obj = parse_file(argv[1], sys);
	printf("sys->obj: %p\n", sys->obj);
	if (!sys->obj)
	{
		system_exit(sys, E_INVALID_INPUT);
	}
	// #else
	// 	/*  generate_from_file() を呼び出してファイルからオブジェクト群を生成 */
	// 	sys->obj = generate_from_file(sys, argv[1]);
	// #endif
	setup_mlx(sys);
	LOG;
	mlx_loop(sys->mlx);
	system_exit(sys, 0);
	return (0);
}
