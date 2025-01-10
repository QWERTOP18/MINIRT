/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:33:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 07:59:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "mlx_handler.h"
# include "system.h"
# include "vector.h"

# define MAX_CAMERA 10

// C 0,0,0   0,0,1  70
//   pos      dir   fov
typedef struct s_camera
{
	t_vec		pos;
	t_vec		dir;
	double		fov;
	t_screen	img;
}				t_camera;

t_camera		*camera_init(t_vec center, t_vec orient, double fov,
					t_sys *sys);

#endif