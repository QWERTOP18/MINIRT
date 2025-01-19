/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:33:11 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/19 18:02:02 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "material.h"
# include "vector.h"

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_intersect
{
	t_pos_vec		pos;
	t_unit_vec		normal;
	double			dist;
	// t_material		*material;
}					t_intersect;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

typedef t_intersect	(*t_isfunc)(t_unit_line ray, void *obj);

/* -----------------------------  INTERSECT   ------------------------------- */

t_intersect			is0(t_unit_line ray, void *obj);
t_intersect			is1(t_unit_line ray, void *obj);
t_intersect			is2(t_unit_line ray, void *obj);
t_intersect			is3(t_unit_line ray, void *obj);
t_intersect			is4(t_unit_line ray, void *obj);
t_intersect			is5(t_unit_line ray, void *obj);
t_intersect			is6(t_unit_line ray, void *obj);
t_intersect			is7(t_unit_line ray, void *obj);
t_intersect			is8(t_unit_line ray, void *obj);
t_intersect			is9(t_unit_line ray, void *obj);

/* -----------------------------   UTILS    --------------------------------- */

t_vec				solve_quadratic_eq(double a, double b, double c);

#endif
