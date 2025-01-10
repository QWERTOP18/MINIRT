/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:35:01 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 13:42:38 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HANDLER_H
# define MLX_HANDLER_H

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

struct		s_screen
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

void		setup_mlx(t_sys *sys);
void		setup_hook(t_sys *sys);

void		render_pixel(const t_screen *screen, int x, int y, int color);

int			exit_handler(t_sys *sys);
int			key_handler(int key, t_sys *sys);
int			mouse_handler(int button, int x, int y, t_sys *sys);
int			loop_handler(t_sys *sys);

#endif