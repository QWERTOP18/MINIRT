/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:40:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 10:49:23 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "system.h"

void	render_pixel(const t_screen *screen, int x, int y)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color_convert(screen->pixels[y][x].color);
}

t_list	*find_nearest_obj(t_unit_line ray, t_list *objs)
{
	double	min_dist;
	t_list	*res;

	//全探索して一番近いものをみつける
	min_dist = __DBL_MAX__;
	return (objs);
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
	int			y;
	int			x;
	t_unit_line	ray;

	ray.pos = camera->pos;
	y = 0;
	while (y < sys->height)
	{
		x = 0;
		while (x < sys->width)
		{
			/*
			ambient + Diffuse + Specular
			*/
			ray.dir = dir(ray.pos, screen_point(x, y, camera));
			update_pixel(ray, sys->obj);
			render_pixel(camera->img, x, y);
			x++;
		}
		y++;
	}
}
