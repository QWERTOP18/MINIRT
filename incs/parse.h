/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:37:59 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/12 19:37:20 by aryamamo         ###   ########.fr       */
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
t_objects	*parse_light(t_objects *objs, char **tokens, int line_num,
				t_sys *sys);
char		*get_next_token(char **p);
t_objects	*parse_ambient(t_objects *objs, char **tokens, int line_num,
				t_sys *sys);
t_objects	*parse_camera(t_objects *objs, char **tokens, int line_num,
				t_sys *sys);
t_objects	*parse_sphere(t_objects *objs, char **tokens, int line_num,
				t_sys *sys);
float		ft_atof(const char **s);
void		error_exit(const char *msg);
int			is_space(char c);
/* -----------------------------  内部関数   --------------------------------- */

#endif