/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:27:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/06 05:46:56 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_line	line(t_pos_vec p1, t_pos_vec p2)
{
	t_line	l;

	l.p1 = p1;
	l.p2 = p2;
	return (l);
}

t_unit_line	unit_line(t_pos_vec pos, t_vec dir)
{
	t_unit_line	unit_l;

	unit_l.pos = pos;
	unit_l.dir = vec_normalize(dir);
	return (unit_l);
}
