/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:41:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 09:19:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_hook(t_sys *sys)
{
	LOG;
	mlx_hook(sys->win, KeyPress, KeyPressMask, key_handler, sys);
	mlx_hook(sys->win, ClientMessage, StructureNotifyMask, exit_handler, sys);
	mlx_mouse_hook(sys->win, mouse_handler, sys);
	mlx_loop_hook(sys->mlx, loop_handler, sys);
}

void	setup_img(t_screen *img, t_sys *sys)
{
	LOG;
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
	LOG;
	sys->win = mlx_new_window(sys->mlx, sys->width, sys->height, "miniRT");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	setup_hook(sys);
}

t_pixel	**pixels_init(int height, int width, t_sys *sys)
{
	t_pixel	**pixels;
	int		i;

	LOG;
	i = 0;
	pixels = xcalloc(height, sizeof(t_pixel *), sys);
	while (i < height)
	{
		pixels[i] = xcalloc(width, sizeof(t_pixel), sys);
		i++;
	}
	return (pixels);
}

void	pixels_deinit(int height, int width, t_pixel **pixels)
{
	int i;

	LOG;
	(void)width;
	if (!pixels)
		return ;
	i = 0;
	while (i < height)
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
}