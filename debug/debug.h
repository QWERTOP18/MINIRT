/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:03:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 09:32:37 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "camera.h"
# include "color.h"
# include "mlx_handler.h"
# include "object.h"
# include "parse.h"
# include "ray.h"
# include "system.h"
# define LOG printf("log :%s\n", __func__)

void		log_obj(t_list *obj);
void		log_objs(t_objects *objs);
t_objects	*generate(t_sys *sys);

#endif