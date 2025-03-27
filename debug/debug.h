/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:03:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/27 09:35:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "camera.h"
# include "color.h"
# include "material.h"
# include "object.h"
# include "parse.h"
# include "raytrace.h"
# include "screen.h"
# include "system.h"
# define LOG dprintf(2, "log :%s\n", __func__)
# define WARNIG dprintf(2, RED "warning :%s" RESET "\n", __func__)

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

/* -----------------------------   CONSOLE   -------------------------------- */
// void		log_obj(t_list *obj);
// void		log_objs(t_objects *objs);
// void		log_vec(char *name, t_vec vec);

/* -----------------------------   PARSE   ---------------------------------- */
t_objects	*generate(t_sys *sys);
