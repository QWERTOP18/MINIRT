/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:26:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 13:20:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"

# define RED x
# define GREEN y
# define BLUE z
typedef t_vec	t_fcol;

unsigned int	fcolor_to_rgb(t_fcol fcol);

#endif