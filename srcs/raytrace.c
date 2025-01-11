/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 14:00:14 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	intersect_dispacher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3};

	return (isfunc[obj->type](ray, obj->data));
}

t_list	*determine_target(t_unit_line ray, t_list *objs)
{
	double	dist;
	double	min_dist;
	t_list	*res;
	t_list	*obj;

	res = NULL;
	min_dist = __DBL_MAX__;
	obj = objs;
	while (obj)
	{
		dist = intersect_dispacher(ray, obj).dist;
		if (dist < min_dist)
		{
			min_dist = dist;
			res = obj;
		}
		obj = obj->next;
	}
	return (res);
}

void	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel)
{
	double	x;

	pixel->obj = determine_target(ray, objs->objs);
	log_obj(pixel->obj);
	if (!pixel->obj)
		return ;
	pixel->intersect = intersect_dispacher(ray, pixel->obj);
	/*
	法線ベクトルを計算
	ONな光源について
		影の判定
		入射、反射ベクトルの計算
	*/
}

// typedef struct s_pixel
// {
// 	t_scaled_col	color;
// 	double			dist;
// 	t_list *obj; // nearest object or NULL
// 	t_unit_vec		ray;
// 	t_unit_vec		normal;
// 	t_pos_vec		intersection;
// 	bool			ishide[MAX_LIGHT];
// 	t_unit_vec		light[MAX_LIGHT];
// 	t_unit_vec		reflect[MAX_LIGHT];
// }					t_pixel;