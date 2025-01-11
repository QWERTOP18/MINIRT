/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:33:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 09:25:06 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "screen.h"
# include "system.h"
# include "vector.h"
# ifndef MAX_CAMERA
#  define MAX_CAMERA 10
# endif

// C 0,0,0   0,0,1  70
//   pos      dir   fov
/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_camera
{
	t_pos_vec	pos;
	t_unit_vec	dir;
	t_rect		screen;
	double		fov;
	t_screen	img;
}				t_camera;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_camera		*camera_init(t_vec pos, t_vec orient, int fov, t_sys *sys);
void			camera_deinit(void *mlx, t_camera *camera[], int size);

#endif