/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conslole.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:30:38 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 09:19:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minirt.h"
#include <stdio.h>

void	log_objs(t_objects *objs)
{
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
}
void	log_obj(t_list *obj)
{
	static char	*name[] = {"sphere", "plane", "cylinder", NULL};

	printf("type: %s\n", name[obj->type]);
}
