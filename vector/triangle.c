/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:24:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 16:32:48 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_triangle	*triangle_new(t_pos_vec p0, t_pos_vec p1, t_pos_vec p2,
		void *material)
{
	t_triangle	*triangle;
	t_vec		edge1;
	t_vec		edge2;

	triangle = ft_calloc(1, sizeof(t_triangle));
	if (!triangle)
		return (NULL);
	triangle->p0 = p0;
	triangle->p1 = p1;
	triangle->p2 = p2;
	triangle->material = material;
	edge1 = vec_sub(p1, p0);
	edge2 = vec_sub(p2, p0);
	triangle->normal = vec_normalize(vec_cross(edge1, edge2));
	return (triangle);
}

void	triangle_clear(t_triangle *triangle)
{
	if (!triangle)
		return ;
	free(triangle->material);
	free(triangle);
}

// bool	is_point_in_triangle(t_pos_vec p, const t_triangle *tri)
// {
// 	t_vec	v0;
// 	t_vec	v1;
// 	t_vec	v2;
// 	double	d00;
// 	double	d01;
// 	double	d11;
// 	double	d20;
// 	double	d21;
// 	double	denom;
// 	double	v;
// 	double	w;
// 	double	u;

// 	v0 = vec_sub(tri->p1, tri->p0);
// 	v1 = vec_sub(tri->p2, tri->p0);
// 	v2 = vec_sub(p, tri->p0);
// 	d00 = vec_dot(v0, v0);
// 	d01 = vec_dot(v0, v1);
// 	d11 = vec_dot(v1, v1);
// 	d20 = vec_dot(v2, v0);
// 	d21 = vec_dot(v2, v1);
// 	denom = d00 * d11 - d01 * d01;
// 	if (fabs(denom) < FT_EPSILON)
// 		return (false); // 面積ゼロ三角形
// 	v = (d11 * d20 - d01 * d21) / denom;
// 	w = (d00 * d21 - d01 * d20) / denom;
// 	u = 1.0 - v - w;
// 	return (u >= 0 && v >= 0 && w >= 0);
// }
