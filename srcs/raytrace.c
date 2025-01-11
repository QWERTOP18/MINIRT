/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 11:22:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*find_nearest_obj(t_unit_line ray, t_list *objs)
{
	double	min_dist;
	t_list	*res;

	//全探索して一番近いものをみつける
	min_dist = __DBL_MAX__;
	return (objs);
}

void	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel)
{
	/*
	一番近いものを見つける
	法線ベクトルを計算
	ONな光源について
		影の判定
		入射、反射ベクトルの計算
	*/
	return ;
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