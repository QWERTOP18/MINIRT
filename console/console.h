#ifndef CONSOLE_H
# define CONSOLE_H

# include "camera.h"
# include "color.h"
# include "material.h"
# include "mlx_handler.h"
# include "object.h"
# include "parse.h"
# include "ray.h"
# include "system.h"
# include <stdio.h>

void	log_obj(t_list *obj);
void	log_objs(t_objects *objs);
void	log_vec(char *name, t_vec vec);

#endif