/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:57:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 00:47:30 by ymizukam         ###   ########.fr       */
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

#endif
