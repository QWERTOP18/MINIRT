/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:41:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 13:49:57 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_hook(t_sys *sys)
{
	mlx_hook(sys->win, KeyPress, KeyPressMask, key_handler, sys);
	mlx_hook(sys->win, ClientMessage, StructureNotifyMask, exit_handler, sys);
	mlx_mouse_hook(sys->win, mouse_handler, sys);
	mlx_loop_hook(sys->mlx, loop_handler, sys);
}

void	setup_mlx(t_sys *sys)
{
	sys->win = mlx_new_window(sys->mlx, sys->height, sys->width, "miniRT");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	setup_hook(sys);
}