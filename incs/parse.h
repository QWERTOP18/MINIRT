/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:37:59 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 01:13:57 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../srcs/parse/get_next_line.h"
# include "libft.h"
# include "system.h"

/* ---------------------------   外部呼び出し   ------------------------------- */
t_objects	*parse_file(char *file, t_sys *sys);

/* -----------------------------  内部関数   --------------------------------- */

#endif