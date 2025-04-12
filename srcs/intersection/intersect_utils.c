/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:59:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 07:23:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersect	intersect_dispatcher(t_unit_line ray, t_list *obj)
{
	static t_isfunc	isfunc[] = {is0, is1, is2, is3, is4, is5, is6, is7};

	return (isfunc[obj->type](ray, obj->data));
}
