/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 04:56:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "minirt.h"
#include "system.h"

unsigned int	color_convert(t_scaled_col scol)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = fmin(255, scol.x * 255);
	green = fmin(255, scol.y * 255);
	blue = fmin(255, scol.z * 255);
	return (red << 16 | green << 8 | blue);
}

t_scaled_col	color_scaler(t_vec color)
{
	color.x /= 255;
	color.y /= 255;
	color.z /= 255;
	return (color);
}

// t_scaled_col	**color_array_init(int height, int width, t_sys *sys)
// {
// 	t_scaled_col	**array;
// 	int		i;

//
// 	i = 0;
// 	array = xcalloc(height, sizeof(t_scaled_col *), sys);
// 	while (i < height)
// 	{
// 		array[i] = xcalloc(width, sizeof(t_scaled_col), sys);
// 		i++;
// 	}
// 	return (array);
// }

// void	color_array_deinit(int height, int width, t_scaled_col **array)
// {
//
// 	(void)width;
// 	if (!array)
// 		return ;
// 	int i = 0;
// 	while (i < height)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// }