/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:42:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 04:09:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*light_init(t_pos_vec pos, t_scaled_col col, double intensity,
		t_sys *sys)
{
	t_light	*light;

	LOG;
	light = xcalloc(1, sizeof(t_light), sys);
	light->pos = pos;
	light->color = col;
	// light-> intensity = intensity;
	light->intensity = vec(1.0, 1.0, 1.0);
	light->ison = True;
	return (light);
}

void	light_deinit(t_light *light[], int size)
{
	int	i;

	LOG;
	if (!light)
		return ;
	i = 0;
	while (i < size)
	{
		free(light[i]);
		i++;
	}
}
