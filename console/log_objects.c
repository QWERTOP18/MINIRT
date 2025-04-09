/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:01:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 05:04:18 by ymizukam         ###   ########.fr       */
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

void	log_objs(t_objects *objs)
{
	if (!objs)
		return ;
	printf(YELLOW BOLD "---- obj -------------------------\n" RESET);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	printf("num_of_light : %d\n", objs->num_of_light);
	printf(YELLOW BOLD "----------------------------------\n" RESET);
	printf("\n");
}
