/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 15:44:20 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

unsigned int	color_convert(t_fcol fcol)
{
	unsigned int red = fcol.x * 255;
	unsigned int green = fcol.y * 255;
	unsigned int blue = fcol.z * 255;
	return (red << 16 | green << 8 | blue);
}