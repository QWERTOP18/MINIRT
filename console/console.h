#ifndef CONSOLE_H
# define CONSOLE_H

# include "camera.h"
# include "color.h"
# include "material.h"
# include "object.h"
# include "parse.h"
# include "raytrace.h"
# include "screen.h"
# include "system.h"
# include <stdio.h>

typedef void	(*console_log)(void *data);

void			log_obj(t_list *obj);
void			log_objs(t_objects *objs);
void			log_objs_detail(t_objects *objs);

void			log_vec(char *name, t_vec vec);
void			log_vec_inline(char *name, t_vec vec);
void			log_light(t_light **light, int size);
void			log_light_detail(t_light **light, int size);
void			log_material(t_material *material);

void			log_pixel(t_pixel **pixel, int y, int x);
void			log_pixel_detail(t_pixel **pixel, int y, int x);

void			l0(void *data);
void			l1(void *data);
void			l2(void *data);
void			l3(void *data);
void			l4(void *data);
void			l5(void *data);
void			l6(void *data);
void			l7(void *data);
void			l8(void *data);
void			l9(void *data);

#endif