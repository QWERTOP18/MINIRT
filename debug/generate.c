#include "../srcs/minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects	*objects;
	t_screen	*img;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 5;
	objects->num_of_light = 1;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = camera_init(vec(0, 0, 40), vec(0, 0, -1), 90, sys);
	objects->camera[1] = camera_init(vec(0, 0, 10), vec(0, 0, -1), 90, sys);
	objects->camera[2] = camera_init(vec(0, 0, -20), vec(0, 0, 1), 90, sys);
	objects->camera[3] = camera_init(vec(0, 40, 0), vec(0, -1, 0), 90, sys);
	objects->camera[4] = camera_init(vec(0, -40, 10), vec(0, 1, 0), 90, sys);
	objects->light[0] = light_init(vec(40, 100, 20), vec(1, 1, 1), 1.0, sys);
	objects->ambient = vec(0.4, 0.4, 0.4);
	// objects->light[1] = light_init(vec(0, 0, 20), vec(1, 1, 1), 1.0, sys);
	/* an image for experiment */
	// img = objects->camera[1]->img;
	// objects->camera[1]->isupdate = False;
	// for (int y = 0; y < sys->height; y++)
	// {
	// 	for (int x = 0; x < sys->width; x++)
	// 	{
	// 		render_pixel(img, x, y, 255);
	// 	}
	// }
	/* ------------------------ */
	objects->objs = ft_lstnew(SPHERE, sphere_new(vec(0, 0, 5), 1, NULL));
	objects->objs->next = ft_lstnew(SPHERE, sphere_new(vec(10, 10, 5), 1,
				NULL));
	objects->objs->next->next = ft_lstnew(PLANE, sphere_new(vec(10, 10, 5), 1,
				NULL));
	// calc1(NULL, objects->list, &objects->camera[1]);
	log_objs(objects);
	return (objects);
}
