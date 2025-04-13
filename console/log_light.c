/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:28:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 01:50:22 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_light(t_light **light, int size)
{
	int	i;

	if (!light)
		return ;
	i = 0;
	while (i < size)
	{
		if (light[i]->ison)
			printf(YELLOW REVERSED "[%d]" RESET " ", i);
		else
			printf("[%d] ", i);
		i++;
	}
	printf("\n");
}
void	log_light_detail(t_light **light, int size)
{
	int	i;

	if (!light)
		return ;
	i = 0;
	while (i < size)
	{
		if (light[i]->ison)
			printf(YELLOW REVERSED "[%d]" RESET " ", i);
		else
			printf("[%d] ", i);
		log_vec_inline("posture", light[i]->pos);
		log_vec_inline("    color", light[i]->color);
		i++;
	}
}
