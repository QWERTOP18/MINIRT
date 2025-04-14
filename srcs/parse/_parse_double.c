/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:59:52 by ymizukam          #+#    #+#             */

/*   Updated: 2025/04/14 12:38:34 by ymizukam         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	handle_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

static int	parse_integer_part(const char *str, double *result, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

static int	parse_decimal_part(const char *str, double *result, int i)
{
	double	decimal_place;

	decimal_place = 0.1;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			*result += (str[i] - '0') * decimal_place;
			decimal_place *= 0.1;
			i++;
		}
	}
	return (i);
}

double	ft_atod(const char *str, bool *res)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	*res = true;
	i = handle_sign(str, &sign);
	i = parse_integer_part(str, &result, i);
	i = parse_decimal_part(str, &result, i);
	if (str[i] != '\0')
	{
		printf("Invalid number format\n");
		*res = false;
		return (0);
	}
	return (result * sign);
}

/**
 * @param lim xに最小値 yに最大値 zに範囲指定をするかどうかをいれて渡す
 * @return errorの場合は*res=falseにして返す
 * usage
 *
 * 0以上の小数を期待する場合
 * parse_double(&res, tokens[2], line, vec(0, __DBL_MAX__, 1));
 *
 * 範囲指定をしない場合
 *  parse_double(res, el[2], line, vec0()))
 */
double	parse_double(bool *res, const char *token, int line, t_vec lim)
{
	double	d;

	d = ft_atod(token, res);
	if (lim.z != 0.0 && (d < lim.x || lim.y < d))
	{
		if (lim.y == __DBL_MAX__)
			printf("line: %d:  field must be positve\n", line);
		else
			printf("line: %d:  field must be in range [%6f, %6f]\n", line,
				lim.x, lim.y);
		*res = false;
	}
	return (d);
}
