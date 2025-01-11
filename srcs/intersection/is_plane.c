/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 13:56:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	is1(t_unit_line ray, void *obj)
{
	t_intersect	is;

	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	return (is);
}
t_intersect	is2(t_unit_line ray, void *obj)
{
	t_intersect	is;

	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	return (is);
}

t_intersect	is3(t_unit_line ray, void *obj)
{
	t_intersect	is;

	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	return (is);
}
