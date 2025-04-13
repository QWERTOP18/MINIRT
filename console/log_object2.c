/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:02:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 15:50:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	l5(void *data)
{
	(void)data;
}

void	l6(void *data)
{
	(void)data;
}

void	l7(void *data)
{
	(void)data;
}

void	l8(void *data)
{
	(void)data;
}

void	log_obj(t_list *obj)
{
	static console_log	l[] = {l0, l1, l2, l3, l4, l5, l6, l7, l8};

	if (!obj)
	{
		printf(RED "object None" RESET "\n");
		return ;
	}
	l[obj->type](obj->data);
	printf("\n");
}
