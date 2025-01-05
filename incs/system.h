/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:20:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 00:40:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 1000

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define E_ALLOCATE -1
# define E_MLX_INIT -2
# define E_WINDOW_CREATE -3
# define E_INVALID_INPUT -4

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_sys
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_list	*objects;
}			t_sys;

#endif