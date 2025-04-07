#include "minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects	*objects;
	t_screen	*img;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 5;
	objects->num_of_light = 1;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = camera_init(vec(0, 3, -20), vec(0, -0.2, 1), 60, sys);
	objects->camera[1] = camera_init(vec(20, 3, 0), vec(-1, 0, 0), 60, sys);
	objects->camera[2] = camera_init(vec(-20, 3, 0), vec(1, 0, 0), 60, sys);
	objects->camera[3] = camera_init(vec(0, 20, 0), vec(0, -1, 0), 60, sys);
	objects->camera[4] = camera_init(vec(0, -40, 10), vec(0, 1, 0), 90, sys);
	objects->light[0] = light_init(vec(40, 100, 20), vec(1, 1, 1), 1.0, sys);
	objects->ambient = vec(0.04, 0, 0);
	objects->objs = ft_lstnew(SPHERE, sphere_new(vec(5, 0, 0), 3,
				material_init(vec(128, 24, 24))));
	objects->objs->next = ft_lstnew(SPHERE, sphere_new(vec(10, 10, 5), 1,
				NULL));
	objects->objs->next->next = ft_lstnew(SPHERE, sphere_new(vec(10, 10, 5), 10,
				NULL));
	/* objects->objs->next->next = ft_lstnew(PLANE, plane_new(vec(0, -4, 0),
				vec(0,
					1, 0), NULL)); */
	/* objects->objs->next->next->next = ft_lstnew(PLANE, plane_new(vec(0, -4,
					0),
				vec(0, 0, -1), NULL));
	objects->objs->next->next->next->next = ft_lstnew(CYLINDER,
			cylinder_new(vec(-5, -1, 0), vec(0, 1, 0), vec(4, 2, 0), NULL)); */
	// calc1(NULL, objects->list, &objects->camera[1]);
	log_objs(objects);
	return (objects);
}
/*
A  0.1      255,255,255
c  0,3,-20    0,-0.2,1       60
c  20,3,0    -1,0,0       60
c  -20,3,0    1,0,0       60
c  0,20,0    0,-1,0       60
l  15,15,-15  0.9         255,255,255
pl 0,-4,0   0,1,0            255,255,0
sp 5,0,0       3          255,0,0
tr -3,-5,-3 3,-5,-3 0,5,0      255,255,255
cy -5,-1,0   0,1,0   4  2 0,255,0
sq 0,-2,-3   1,1,-1       3          0,176,176
sq 5,-2,-3   1,-1,1       3          100,0,176
 */