/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:23:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 01:32:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef OBJECT_H
# define OBJECT_H


typedef struct	s_vec 
{
	double		x;
	double		y;
	double		z;
} t_vec;

typedef struct	s_sphere 
{ 
  t_vec		center;
  double		radius;
}				t_sphere;

typedef struct	s_plane 
{
  t_vec		center;
  t_vec		dir;
}				t_plane;


typedef struct	s_camera
{
  t_vec    pos;
  t_vec    dir;
  // t_vec    up;
  // double    fov;
  // double    aspect;
  // double    near;
  // double    far;
} t_camera;

typedef struct  s_light
{
  t_vec    pos;
  double    intensity;
  struct s_light *next;
} t_light;



//object を管理するための構造体

typedef struct  s_objects
{
  t_camera *camera;
  int num_of_camera;
  int id_of_camera;

} t_objects;

#endif
