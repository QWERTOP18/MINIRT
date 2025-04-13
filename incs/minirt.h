/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:57:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 17:12:58 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../console/console.h"
# include "camera.h"
# include "color.h"
# include "intersection.h"
# include "light.h"
# include "material.h"
# include "object.h"
# include "parse.h"
# include "raytrace.h"
# include "screen.h"
# include "system.h"
# include <math.h>
# ifndef SUBMIT
#  include "../debug/debug.h"
# else
#  define LOG ""
#  define WARNIG ""
# endif

t_objects	*parse_file(char *file, t_sys *sys);

#endif
