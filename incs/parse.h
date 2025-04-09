/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:37:59 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/09 19:12:11 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../srcs/parse/get_next_line.h"
# include "libft.h"
# include "system.h"

/* ---------------------------   外部呼び出し   ------------------------------- */
// t_objects	*parse_file(char *file, t_sys *sys);
t_objects	*generate_from_file(t_sys *sys, const char *filename);

/* -----------------------------  内部関数   --------------------------------- */

#endif