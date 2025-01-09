/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:37:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/09 21:48:09 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "system.h"

int	calc1(t_unit_line *ray, t_list *lobj, t_camera *camera);

int	calc2(t_unit_line *ray, t_list *lobj, t_camera *camera);

#endif