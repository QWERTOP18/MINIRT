/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:59:52 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 04:01:06 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

double	parse_double(bool *res, const char *token, int line)
{
	// todo 失敗したら*res = false　にしエラーメッセージをはく
	return (atof(token));
}
