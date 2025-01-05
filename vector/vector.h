/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:19:29 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 03:26:16 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}			t_vec;

t_vec		vec(double x, double y, double z);
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_mul(t_vec v, double scalar);
// t_vec    vec_div(t_vec v, double scalar);
double		vec_dot(t_vec v1, t_vec v2);
t_vec		vec_cross(t_vec v1, t_vec v2);
double		vec_magnitude(t_vec v);
t_vec		vec_normalize(t_vec v);

#endif