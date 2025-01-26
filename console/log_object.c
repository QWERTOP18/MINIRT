/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:02:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/20 10:58:05 by ymizukam         ###   ########.fr       */
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
	log_light(objs->light, objs->num_of_light);
	printf(YELLOW BOLD "----------------------------------\n" RESET);
	printf("\n");
}

void	l0(void *data)
{
	const t_sphere	*sp = (const t_sphere *)data;

	log_vec("sphere", sp->center);
	printf("r:  %8.2f\n", sp->radius);
}
void	l1(void *data)
{
	const t_plane	*pl = (const t_plane *)data;

	log_vec("plane normal", pl->normal);
	log_vec("plane center", pl->pos);
	// printf("r:  %8.2f\n", sp->radius);
}
void	l2(void *data)
{
}
void	l3(void *data)
{
}

void	log_obj(t_list *obj)
{
	static char			*name[] = {"sphere", "plane", "cylinder", NULL};
	static console_log	l[] = {l0, l1, l2, l3};

	if (!obj)
	{
		printf(RED "object None" RESET "\n");
		return ;
	}
	// printf("type: %s\n", name[obj->type]);
	l[obj->type](obj->data);
	printf("\n");
}
