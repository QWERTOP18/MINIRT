/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:53:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 13:56:30 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	is0(t_unit_line ray, void *obj)
{
	t_intersect	is;

	is.dist = __DBL_MAX__;
	is.normal = vec(0, 0, 0);
	is.pos = vec(0, 0, 0);
	return (is);
}
