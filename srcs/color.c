/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 08:17:41 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "minirt.h"
#include "system.h"

unsigned int	color_convert(t_fcol fcol)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = fcol.x * 255;
	green = fcol.y * 255;
	blue = fcol.z * 255;
	return (red << 16 | green << 8 | blue);
}

// t_fcol	**color_array_init(int height, int width, t_sys *sys)
// {
// 	t_fcol	**array;
// 	int		i;

// 	LOG;
// 	i = 0;
// 	array = xcalloc(height, sizeof(t_fcol *), sys);
// 	while (i < height)
// 	{
// 		array[i] = xcalloc(width, sizeof(t_fcol), sys);
// 		i++;
// 	}
// 	return (array);
// }

// void	color_array_deinit(int height, int width, t_fcol **array)
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