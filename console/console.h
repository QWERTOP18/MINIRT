#ifndef CONSOLE_H
# define CONSOLE_H

# include "camera.h"
# include "color.h"
# include "material.h"
# include "object.h"
# include "parse.h"
# include "ray.h"
# include "screen.h"
# include "system.h"
# include <stdio.h>

void	log_obj(t_list *obj);
void	log_objs(t_objects *objs);
void	log_vec(char *name, t_vec vec);
void	log_light(t_light **light, int size);

void	log_pixel(t_pixel **pixel, int y, int x);

#endif