/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:19:31 by teando            #+#    #+#             */
/*   Updated: 2025/04/14 11:41:28 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *, int))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		del(current->data, current->type);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
