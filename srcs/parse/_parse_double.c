/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:59:52 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 10:21:55 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

double	ft_atod(const char *str, bool *res)
{
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

	// todo 失敗したら*res = false　にしエラーメッセージをはく
	d = atof(token);
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
