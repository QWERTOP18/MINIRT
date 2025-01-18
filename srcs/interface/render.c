/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:40:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 15:38:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "system.h"

void	render_pixel(const t_screen *screen, int x, int y, unsigned int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

t_pos_vec	screen_point(int x, int y, t_camera *c)
{
	t_vec	dxy;
	double	dx;
	double	dy;

	dx = x - (double)c->img->width / 2;
	dy = y - (double)c->img->height / 2;
	dxy = vec_add(vec_mul(c->screen.wdir, dx), vec_mul(c->screen.hdir, dy));
	return (vec_add(c->screen.pos, dxy));
}

void	render_img(t_camera *camera, t_sys *sys)
{
	int				y;
	int				x;
	unsigned int	color;
	t_unit_line		ray;

	LOG;
	camera->isupdate = False;
	ray.pos = camera->pos;
	y = 0;
	while (y < sys->height)
	{
		x = 0;
		while (x < sys->width)
		{
			ray.dir = dir(ray.pos, screen_point(x, y, camera));
			color = update_pixel(ray, sys->obj, &camera->img->pixels[y][x]);
			render_pixel(camera->img, x, y, color);
			x++;
		}
		y++;
	}
}
