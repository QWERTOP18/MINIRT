/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 09:54:17 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	expect_len(int num, char **tokens, int line)
{
	int	i;

	i = 0;
	// i = 0 は存在することが確定している
	while (++i < num)
	{
		if (!tokens[i])
		{
			printf("line: %d: Insufficient parameters\n", line);
			return (false);
		}
	}
	if (tokens[i])
	{
		printf("line: %d: too many parameters\n", line);
		return (false);
	}
	return (true);
}
