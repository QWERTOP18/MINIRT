#include "../srcs/minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects	*objects;
	t_screen	*img;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 2;
	objects->num_of_light = 2;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = camera_init(vec(5, 0, 0), vec(0, 0, -1), 90, sys);
	objects->camera[1] = camera_init(vec(5, 0, 5), vec(0, 1, 0), 45, sys);
	objects->light[0] = light_init(vec(0, 0, 20), vec(1, 1, 1), 1.0, sys);
	objects->light[1] = light_init(vec(0, 0, 20), vec(1, 1, 1), 1.0, sys);
	/* an image for experiment */
	img = objects->camera[0]->img;
	for (int y = 0; y < sys->height; y++)
	{
		for (int x = 0; x < sys->width; x++)
		{
			render_pixel(img, x, y, 0x000FF);
		}
	}
	/* ------------------------ */
	objects->objs = ft_lstnew(SPHERE, sphere_new(vec(0, 0, 5), 1));
	objects->objs->next = ft_lstnew(SPHERE, sphere_new(vec(10, 10, 5), 1));
	// calc1(NULL, objects->list, &objects->camera[1]);
	log_objs(objects);
	return (objects);
}
