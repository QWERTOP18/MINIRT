#include "../srcs/minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects *objects;
	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 2;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = *camera_init(vec(0, 0, 0), vec(0, 0, -1), 90, sys);
	objects->camera[1] = *camera_init(vec(0, 0, 5), vec(0, 1, 0), 90, sys);
	for (size_t hh = 0; hh < 100; hh++)
	{
		for (size_t ww = 100; ww < 200; ww++)
		{
			render_pixel(&objects->camera[0].img, ww, hh, 0xFF0000);
		}
	}
	objects->objs = ft_lstnew(SPHERE, sphere_new(vec(0, 0, 5), 1));

	objects->objs->next = ft_lstnew(SPHERE, sphere_new(vec(10, 10, 5), 1));
	// calc1(NULL, objects->list, &objects->camera[1]);
	log_objs(objects);
	return (objects);
}