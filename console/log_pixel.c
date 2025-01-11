/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:57:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 09:46:10 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_pixel(t_pixel **pixel, int y, int x)
{
	printf(CYAN BOLD "-- (%4d, %4d) ------------------\n" RESET, y, x);
	// printf(UNDERLINE BOLD "%s" RESET "\n", name);
	if (pixel[y][x].obj)
	{
		log_obj(pixel[y][x].obj);
		printf("dist :  %f\n", pixel[y][x].dist);
		log_vec("intersection", pixel[y][x].intersection);
	}
	printf(CYAN BOLD "----------------------------------\n" RESET);
	printf("\n");
}