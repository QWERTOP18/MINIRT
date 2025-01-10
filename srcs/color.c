/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:19 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 13:20:42 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

unsigned int	fcolor_to_rgb(t_fcol fcol)
{
	unsigned int red = fcol.RED * 255;
	unsigned int green = fcol.GREEN * 255;
	unsigned int blue = fcol.BLUE * 255;
	return (red << 16 | green << 8 | blue);
}