/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:57:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 01:57:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_pixel(t_pixel **pixel, int y, int x)
{
	printf(CYAN BOLD "-- (%04d, %04d) ------------------\n" RESET, y, x);
	if (pixel[y][x].obj)
	{
		log_obj_inline(pixel[y][x].obj);
		printf("dist :  %f\n", pixel[y][x].intersect.dist);
	}
	printf(CYAN BOLD "----------------------------------\n" RESET);
	printf("\n");
}
void	log_pixel_detail(t_pixel **pixel, int y, int x)
{
	printf(CYAN BOLD "-- (%04d, %04d) ------------------\n" RESET, y, x);
	if (pixel[y][x].obj)
	{
		log_obj(pixel[y][x].obj);
		printf(UNDERLINE RED CYAN "intersection" RESET "\n");
		printf("dist :  %f\n", pixel[y][x].intersect.dist);
		log_vec_inline("pos", pixel[y][x].intersect.pos);
		log_vec_inline("norm", pixel[y][x].intersect.normal);
	}
	printf(CYAN BOLD "----------------------------------\n" RESET);
	printf("\n");
}
