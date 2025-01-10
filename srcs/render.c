/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:40:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 08:01:00 by ymizukam         ###   ########.fr       */
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

void	raytrace(t_camera *camera, t_sys *sys)
{
	int		y;
	int		x;
	t_list	*head;

	head = y;
	head = y = 0;
	x = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			//座標変換（スケールを変えるだけ)
			//もっとも近いobjectを探す
			//光を計算してRGBに落とし込む
			render_pixel(&camera->img, x, y, 0xFF0000);
		}
	}
}
