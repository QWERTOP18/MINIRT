/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:02:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 21:04:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_objs(t_objects *objs)
{
	printf(YELLOW BOLD "---- obj -------------------------\n" RESET);
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
	printf(YELLOW BOLD "----------------------------------\n" RESET);
	printf("\n");
}

void	log_obj(t_list *obj)
{
	static char	*name[] = {"sphere", "plane", "cylinder", NULL};

	printf("type: %s\n", name[obj->type]);
	printf("\n");
}
