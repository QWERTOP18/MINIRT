/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:23:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 20:11:22 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#include "camera.h"
#include "color.h"
#include "light.h"
#include "vector.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	TRIANGLE,
	CONE,
	ELLIPSOID,
	ERROR = -1,
} t_obj_type;

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

struct s_objects
{
	t_camera *camera[MAX_CAMERA];
	int num_of_camera;
	int id_of_camera;
	t_light *light[MAX_LIGHT];
	int num_of_light;
	t_list *objs;
	t_scaled_col ambient;
};

// sp 0,0,0 12 10,20,20
//  center diameter RGB
// typedef struct s_sphere
// {
// 	t_vec			center;
// 	double			radius;
// }					t_sphere;

// typedef struct s_plane
// {
// 	t_vec	center;
// 	t_vec	dir;
// }			t_plane;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

void objs_deinit(t_objects *objs);

#endif
