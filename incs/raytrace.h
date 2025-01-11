/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:37:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H
# include "system.h"

// int	calc1(t_unit_line *ray, t_list *lobj, t_camera *camera);

// int	calc2(t_unit_line *ray, t_list *lobj, t_camera *camera);

void			*update(t_sys *sys);
unsigned int	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel);
void			render_img(t_camera *camera, t_sys *sys);

#endif