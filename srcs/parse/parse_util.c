/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:16 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 19:35:59 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vector.h"

t_vec	parse_vector(const char *line)
{
	return (vec(0, 0, 0));
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

char	*get_next_token(char **p)
{
	char	*start;

	while (**p && is_space(**p))
		(*p)++;
	if (**p == '\0')
		return (NULL);
	start = *p;
	while (**p && !is_space(**p))
		(*p)++;
	if (**p)
	{
		**p = '\0';
		(*p)++;
	}
	return (start);
}
