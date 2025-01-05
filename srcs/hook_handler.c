/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 00:38:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_handler.h"

int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	// if (button == SCROLL_UP)
	// 	zoom_screen(sys, 1 / 1.1, x, y);
	// if (button == SCROLL_DOWN)
	// 	zoom_screen(sys, 1.1, x, y);
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	if (key == ESCAPE)
		exit_handler(sys);
	// if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	// 	pan_screen(sys, key - LEFT);
	return (0);
}

int	exit_handler(t_sys *sys)
{
	mlx_destroy_image(sys->mlx, sys->img.img);
	mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	mlx_loop_end(sys->mlx);
	free(sys->mlx);
	system_exit(sys, 0);
	return (0);
}
