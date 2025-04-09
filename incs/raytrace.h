/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:56:57 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/10 05:39:07 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H
# include "system.h"

void			*update(t_sys *sys);
unsigned int	update_pixel(t_unit_line ray, t_objects *objs, t_pixel *pixel);
void			render_img(t_camera *camera, t_sys *sys);

t_list			*determine_target(t_unit_line ray, t_list *objs);

t_scaled_col	cal_diffuse(t_unit_vec lightdir, t_unit_vec normal,
					t_light *light, t_scaled_col obj_color);
t_scaled_col	cal_specular(t_unit_vec ray_inverse, t_unit_vec lightdir,
					t_unit_vec normal, t_light *light);
bool			is_interrupted(t_light *light, t_intersect is, t_list *objs);

t_scaled_col	cal_col(t_unit_line ray, t_light *light, t_intersect intersect,
					t_list *objs);
#endif