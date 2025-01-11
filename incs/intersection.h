/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:33:11 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 13:54:41 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "vector.h"

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_intersect
{
	t_pos_vec		pos;
	t_unit_vec		normal;
	double			dist;
}					t_intersect;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

typedef t_intersect	(*t_isfunc)(t_unit_line ray, void *obj);

t_intersect			is0(t_unit_line ray, void *obj);
t_intersect			is1(t_unit_line ray, void *obj);
t_intersect			is2(t_unit_line ray, void *obj);
t_intersect			is3(t_unit_line ray, void *obj);

#endif
