/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:23:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 00:29:19 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SHAPE_H
# define SHAPE_H


typedef struct	s_vec 
{
	double		x;
	double		y;
	double		z;
} t_vec;

typedef struct	s_sphere 
{ 
  t_vec		center;
  double		radius;
}				t_sphere;

typedef struct	s_plane 
{
  t_vec		center;
  t_vec		dir;
}				t_plane;


#endif
