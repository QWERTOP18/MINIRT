/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:57:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/09 22:29:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_pixel(t_pixel **pixel, int y, int x)
{
	printf(CYAN BOLD "-- (%04d, %04d) ------------------\n" RESET, y, x);
	// printf(UNDERLINE BOLD "%s" RESET "\n", name);
	if (pixel[y][x].obj)
	{
		log_obj(pixel[y][x].obj);
		printf("dist :  %f\n", pixel[y][x].intersect.dist);
		log_vec("intersection pos", pixel[y][x].intersect.pos);
		log_vec("intersection norm", pixel[y][x].intersect.normal);
	}
	printf(CYAN BOLD "----------------------------------\n" RESET);
	printf("\n");
}
