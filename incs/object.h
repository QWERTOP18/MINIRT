/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:23:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 02:17:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

// sp 0,0,0 12 10,20,20
//  center diameter RGB
typedef struct s_sphere
{
	t_vec			center;
	double			radius;
}					t_sphere;

typedef struct s_plane
{
	t_vec			center;
	t_vec			dir;
}					t_plane;

typedef struct s_light
{
	t_vec			pos;
	double			intensity;
	struct s_light	*next;
}					t_light;

#endif
