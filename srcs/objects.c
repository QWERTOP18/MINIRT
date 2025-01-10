/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:01:24 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/11 07:57:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	objs_deinit(t_objects *objs)
{
	LOG;
	if (!objs)
		return ;
	//
	ft_lstclear(&objs->objs, free);
	free(objs);
}