/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:29:26 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 01:48:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_handler.h"
#include "system.h"

int	loop_handler(t_sys *sys)
{
	// calculate(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, sys->img.img, 0, 0);
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
	sys = system_init(argv[1]);
	setup_hook(sys);
	mlx_loop(sys->mlx);
	system_exit(sys, 0);
}

/*

* main
* system init
*** parse allocate
* setup hook



*/