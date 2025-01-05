/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:20:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 02:25:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 1000

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "object.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define E_ALLOCATE -1
# define E_MLX_INIT -2
# define E_WINDOW_CREATE -3
# define E_INVALID_INPUT -4

# define MAX_CAMERA 10

typedef struct s_screen
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	// int			width;
	// int			height;
}				t_screen;

// C 0,0,0   0,0,1  70
//   pos      dir   fov
typedef struct s_camera
{
	t_vec		pos;
	t_vec		dir;
	double		fov;
	t_screen	img;
}				t_camera;

// object を管理するための構造体
typedef struct s_objects
{
	t_camera	camera[MAX_CAMERA];
	int			num_of_camera;
	int			id_of_camera;
	t_list		list;
}				t_objects;

typedef struct s_sys
{
	void		*mlx;
	void		*win;
	t_screen	img;
	t_objects	*obj;
}				t_sys;

t_sys			*system_init(char *file);
void			system_exit(t_sys *sys, int status);

#endif