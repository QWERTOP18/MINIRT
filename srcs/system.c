/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:00:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 11:19:57 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_handler.h"
#include "parse.h"
#include "system.h"

void	system_exit(t_sys *sys, int status)
{
	if (status == E_INVALID_INPUT)
	{
		// ft_putstr_fd(ERRMSG1, 2);
		// ft_putstr_fd(ERRMSG2, 2);
	}
	if (!sys)
		exit(status);
	if (!sys->mlx)
		exit(status);
	objs_deinit(sys->mlx, sys->obj);
	mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	mlx_loop_end(sys->mlx);
	free(sys->mlx);
	free(sys);
	exit(status);
}

t_sys	*system_init(void)
{
	t_sys	*sys;

	sys = ft_calloc(1, sizeof(t_sys));
	if (!sys)
		system_exit(NULL, E_ALLOCATE);
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	sys->win = mlx_new_window(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "miniRT");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	// sys->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	// if (!sys->img.img)
	// 	system_exit(NULL, E_ALLOCATE);
	// sys->img.addr = mlx_get_data_addr(sys->img.img, &sys->img.bits_per_pixel,
	// 		&sys->img.line_length, &sys->img.endian);
	return (sys);
}
