/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/14 21:21:39 by ymizukam         ###   ########.fr       */
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

	// if (scol.x > 1 || scol.y > 1 || scol.z > 1)
	// 	WARNIG;
	red = fmin(255, scol.x * 255);
	green = fmin(255, scol.y * 255);
	blue = fmin(255, scol.z * 255);
	return (red << 16 | green << 8 | blue);
}

// t_scaled_col	**color_array_init(int height, int width, t_sys *sys)
// {
// 	t_scaled_col	**array;
// 	int		i;

// 	LOG;
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
// 	LOG;
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