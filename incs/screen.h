/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:01 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 08:19:34 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "color.h"
# include "light.h"
# include "mlx.h"
# include "mlx_int.h"
# include "system.h"

# define ESCAPE 0xFF1B
# define LSHIFT 0xFFE1
# define RSHIFT 0xFFE2

# define LEFT 0xFF51
# define UP 0xFF52
# define RIGHT 0xFF53
# define DOWN 0xFF54

# define LEFT_CLICK 1
# define CENTER_CLICK 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// # define DELTA 0.01
/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_pixel
{
	t_fcol		color;
	double		dist;
	t_list *obj; // nearest object or NULL
	t_unit_vec	ray;
	t_unit_vec	normal;
	t_pos_vec	intersection;
	bool		ishide[MAX_LIGHT];
	t_unit_vec	light[MAX_LIGHT];
	t_unit_vec	reflect[MAX_LIGHT];
}				t_pixel;

struct			s_screen
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	// t_fcol	**color_arr;
	t_pixel		**pixels;
};

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

/* -----------------------------   SET UP   --------------------------------- */

void			setup_mlx(t_sys *sys);
void			setup_hook(t_sys *sys);
void			setup_img(t_screen *img, t_sys *sys);
t_pixel			**pixels_init(int height, int width, t_sys *sys);
void			pixels_deinit(int height, int width, t_pixel **pixels);

/* -----------------------------   RENDER   --------------------------------- */

void			render_pixel(const t_screen *screen, int x, int y);
// void			render_img(t_camera *camera, t_sys *sys);

/* ----------------------------   HANDLER   --------------------------------- */

int				exit_handler(t_sys *sys);
int				key_handler(int key, t_sys *sys);
int				mouse_handler(int button, int x, int y, t_sys *sys);
int				loop_handler(t_sys *sys);

#endif
