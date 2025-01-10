/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 15:11:06 by ymizukam         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_sys	*sys;

	if (argc != 2)
		system_exit(NULL, E_INVALID_INPUT);
	sys = system_init();
	sys->obj = parse_file(argv[1], sys);
	setup_mlx(sys);
	mlx_loop(sys->mlx);
	system_exit(sys, 0);
}

/*

* main
* system init
* parse
* setup hook



*/