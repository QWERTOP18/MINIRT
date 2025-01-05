/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:36:50 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 05:40:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_unit_line	line_normalize(t_line l)
{
	t_unit_line	unit_l;
	t_vec		dir;

	dir = vec_sub(l.p2, l.p1);
	unit_l.dir = vec_normalize(dir);
	unit_l.pos = l.p1;
	return (unit_l);
}
