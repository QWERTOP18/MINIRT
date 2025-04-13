/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:56:57 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 18:39:46 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H
# include "system.h"

void			*update(t_sys *sys);
unsigned int	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel);
void			render_img(t_camera *camera, t_sys *sys);

t_list			*determine_target(t_unit_line ray, t_list *objs);

bool			is_interrupted(t_light *light, t_intersect is, t_list *objs);

t_scaled_col	cal_col(t_unit_line ray, t_light *light, t_intersect intersect,
					t_list *objs);
#endif