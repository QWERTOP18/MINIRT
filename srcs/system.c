/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:00:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 02:17:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "system.h"

t_objects	*parse_file(char *file, t_sys *sys)
{
	t_objects	*objects;
	int			fd;
	char		*line;

	objects = ft_calloc(1, sizeof(t_objects));
	if (!objects)
		system_exit(sys, E_ALLOCATE);
#ifdef NOINPUT
#else
	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_exit(sys, E_INVALID_INPUT);
	line = get_next_line(fd);
	while (line)
	{
		// if (is_valid_line(line))
		//    add_object(objects, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
#endif
	return (objects);
}

void	system_exit(t_sys *sys, int status)
{
	if (status == E_INVALID_INPUT)
	{
		// ft_putstr_fd(ERRMSG1, 2);
		// ft_putstr_fd(ERRMSG2, 2);
	}
	free(sys);
	exit(status);
}

t_sys	*system_init(char *file)
{
	t_sys	*sys;

	sys = ft_calloc(1, sizeof(t_sys));
	if (!sys)
		system_exit(NULL, E_ALLOCATE);
	sys->obj = parse_file(file, sys);
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	sys->win = mlx_new_window(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "FRACTOL");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	sys->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	if (!sys->img.img)
		system_exit(NULL, E_ALLOCATE);
	sys->img.addr = mlx_get_data_addr(sys->img.img, &sys->img.bits_per_pixel,
			&sys->img.line_length, &sys->img.endian);
	return (sys);
}
