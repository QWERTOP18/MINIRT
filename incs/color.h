/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:26:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 11:20:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "system.h"
# include "vector.h"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"

# define BOLD "\033[1m"

# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define REVERSED "\033[7m"
# define HIDDEN "\033[8m"

// # define RED x
// # define GREEN y
// # define BLUE z
typedef t_vec	t_scaled_col;

unsigned int	color_convert(t_scaled_col scol);
// t_scaled_col			**color_array_init(int height, int width, t_sys *sys);
// void			color_array_deinit(int height, int width, t_scaled_col **array);

#endif