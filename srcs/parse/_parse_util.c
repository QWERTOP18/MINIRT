/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 06:39:03 by ymizukam         ###   ########.fr       */
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

float	ft_atof(const char **s)
{
	int			sign;
	float		result;
	float		frac;
	float		divisor;
	const char	*p = *s;

	sign = 1;
	result = 0;
	frac = 0;
	divisor = 1;
	if (*p == '-')
	{
		sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		result = result * 10 + (*p - '0');
		p++;
	}
	if (*p == '.')
	{
		p++;
		while (*p >= '0' && *p <= '9')
		{
			frac = frac * 10 + (*p - '0');
			divisor *= 10;
			p++;
		}
	}
	*s = p;
	return (sign * (result + frac / divisor));
}

void	error_exit(const char *msg)
{
	printf("Error %s\n", msg);
	exit(1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r');
}
