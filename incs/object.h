/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:23:07 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 05:01:30 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,

}			t_obj_type;

// sp 0,0,0 12 10,20,20
//  center diameter RGB
// typedef struct s_sphere
// {
// 	t_vec			center;
// 	double			radius;
// }					t_sphere;

typedef struct s_plane
{
	t_vec	center;
	t_vec	dir;
}			t_plane;

#endif
