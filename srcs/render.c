/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:40:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 14:02:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "system.h"

void	render_pixel(const t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

t_list	*find_nearest_obj(t_unit_line ray, t_list *objs)
{
	double	min_dist;
	t_list	*res;

	//全探索して一番近いものをみつける
	min_dist = __DBL_MAX__;
	return (objs);
}

void	raytrace(t_camera *camera, t_sys *sys)
{
	int			y;
	int			x;
	t_list		*target;
	t_unit_line	ray;
	t_fcol		fcol;

	ray.pos = camera->pos;
	y = 0;
	while (y < sys->height)
	{
		x = 0;
		while (x < sys->width)
		{
			//座標変換（スケールを変えるだけ)
			//もっとも近いobjectを探す
			//光を計算してRGBに落とし込む
			target = find_nearest_obj(ray, sys->obj->objs);
			render_pixel(&camera->img, x, y, fcolor_to_rgb(fcol));
		}
	}
}
