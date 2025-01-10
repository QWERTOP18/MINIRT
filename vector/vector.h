/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:19:29 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/10 07:41:57 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>

typedef struct s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_unit_vec;
typedef t_vec	t_pos_vec;

typedef struct s_line
{
	t_pos_vec	p1;
	t_pos_vec	p2;
}				t_line;

typedef struct s_unit_line
{
	t_pos_vec	pos;
	t_unit_vec	dir;
}				t_unit_line;

typedef struct s_sphere
{
	t_pos_vec	center;
	double		radius;
}				t_sphere;

t_vec			vec(double x, double y, double z);
t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_mul(t_vec v, double scalar);
// t_vec    vec_div(t_vec v, double scalar);
double			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_cross(t_vec v1, t_vec v2);
double			vec_magnitude(t_vec v);
t_unit_vec		vec_normalize(t_vec v);

t_line			line(t_pos_vec p1, t_pos_vec p2);
double			line_distance(t_line l, t_pos_vec p);
t_unit_line		unit_line(t_pos_vec pos, t_vec dir);

t_unit_line		line_normalize(t_line l);

// t_sphere		sphere(t_vec center, double radius);
double			sphere_distance(t_sphere s, t_vec p);

t_sphere		*sphere_new(t_pos_vec center, double radius);

#endif