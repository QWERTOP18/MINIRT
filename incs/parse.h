/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:37:59 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 12:31:23 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../srcs/parse/get_next_line.h"
# include "libft.h"
# include "material.h"
# include "object.h"
# include "system.h"
# include "vector.h"

# define MAX_INPUT_LINE 1024

/* ---------------------------   外部呼び出し   ------------------------------- */

t_objects	*parse_file(char *file, t_sys *sys);

/* -----------------------------  内部関数   --------------------------------- */

bool		parse_light(t_objects *objs, char **tokens, int line, t_sys *sys);
bool		parse_camera(t_objects *objs, char **tokens, int line, t_sys *sys);

bool		parse_ambient(t_objects *objs, char **tokens, int line);
bool		parse_sphere(t_objects *objs, char **tokens, int line);
bool		parse_cylinder(t_objects *objs, char **tokens, int line);
bool		parse_cone(t_objects *objs, char **tokens, int line);
bool		parse_plane(t_objects *objs, char **tokens, int line);

/* -----------------------------  補助関数   --------------------------------- */

bool		expect_len(int num, char **tokens, int line);

t_vec		parse_vector(bool *res, const char *token, int line);
t_vec		parse_color(bool *res, const char *token, int line);
double		parse_double(bool *res, const char *token, int line, t_vec lim);

void		deinit_parse_stack(t_sys *sys, t_objects *objects);
int			open_rtfile(const char *file);

#endif