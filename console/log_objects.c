/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:01:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 03:24:40 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	log_objs(t_objects *objs)
{
	if (!objs)
		return ;
	printf(YELLOW BOLD "---- obj -------------------------\n" RESET);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	log_vec_inline("ambient:", objs->ambient);
	printf("num_of_light : %d\n", objs->num_of_light);
	printf(YELLOW BOLD "----------------------------------\n" RESET);
	printf("\n");
}

void	log_objs_iteration(t_list *lst)
{
	while (lst)
	{
		log_obj_inline(lst);
		printf("\n");
		lst = lst->next;
	}
}

void	log_objs_detail(t_objects *objs)
{
	if (!objs)
		return ;
	printf(YELLOW BOLD "---- obj -------------------------\n" RESET);
	printf("num_of_objs  : %d\n", ft_lstsize(objs->objs));
	log_objs_iteration(objs->objs);
	printf("num_of_camera: %d\n", objs->num_of_camera);
	printf("id_of_camera : %d\n", objs->id_of_camera);
	log_vec_inline("ambient:", objs->ambient);
	printf("num_of_light : %d\n", objs->num_of_light);
	log_light_detail(objs->light, objs->num_of_light);
	printf(YELLOW BOLD "----------------------------------\n" RESET);
	printf("\n");
}

void	log_obj(t_list *obj)
{
	static console_log	l[] = {l0, l1, l2, l3, l4, l5, l6, l7, l8};

	if (!obj)
	{
		printf(RED "object None" RESET "\n");
		return ;
	}
	l[obj->type](obj->data);
	printf("\n");
}
void	log_obj_inline(t_list *obj)
{
	static console_log	ls[] = {ls0, ls1, ls2, ls3, ls4, ls5, ls6, ls7, ls8};

	if (!obj)
	{
		printf(RED "object None" RESET "\n");
		return ;
	}
	ls[obj->type](obj->data);
}
