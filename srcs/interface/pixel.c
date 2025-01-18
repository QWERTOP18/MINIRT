/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:26:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 11:26:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	int	i;

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
