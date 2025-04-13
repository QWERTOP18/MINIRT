/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:41:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 04:56:33 by ymizukam         ###   ########.fr       */
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

void	setup_img(t_screen *img, t_sys *sys)
{
	img->height = sys->height;
	img->width = sys->width;
	img->img = mlx_new_image(sys->mlx, sys->width, sys->height);
	if (!img->img)
		system_exit(NULL, E_ALLOCATE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->pixels = pixels_init(img->height, img->width, sys);
}

void	setup_mlx(t_sys *sys)
{
	sys->win = mlx_new_window(sys->mlx, sys->width, sys->height, "miniRT");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	setup_hook(sys);
}
