/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conslole.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:30:38 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 15:47:15 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minirt.h"
#include <stdio.h>

void	log_objs(t_objects *objs)
{
	printf("---- " YELLOW BOLD "obj" RESET " -------------------------\n");
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
	printf("----------------------------------\n");
	printf("\n");
}
void	log_obj(t_list *obj)
{
	static char	*name[] = {"sphere", "plane", "cylinder", NULL};

	printf("type: %s\n", name[obj->type]);
	printf("\n");
}

void	log_vec(t_vec vec)
{
	printf("---- " CYAN BOLD "vec" RESET " -------------------------\n");
	printf("x:   %f\n", vec.x);
	printf("y:   %f\n", vec.y);
	printf("z:   %f\n", vec.z);
	printf("----------------------------------\n");
	printf("\n");
}