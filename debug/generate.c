#include "minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects	*objects;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 5;
	objects->num_of_light = 1;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = camera_init(vec(50, 10, 0), vec(-1, 0, 0), 60, sys);
	objects->camera[1] = camera_init(vec(0, 3, -20), vec(0, -0.2, 1), 60, sys);
	objects->camera[2] = camera_init(vec(-20, 3, 0), vec(1, 0, 0), 60, sys);
	objects->camera[3] = camera_init(vec(0, 20, 0), vec(0, -1, 0), 60, sys);
	objects->camera[4] = camera_init(vec(0, -40, 10), vec(0, 1, 0), 90, sys);
	objects->light[0] = light_init(vec(0, 40, 0), vec(1, 1, 1), 1.0, sys);
	objects->ambient = color_scaler(vec(0, 20, 30));
	/**
		* SPHERE
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(SPHERE, sphere_new(vec(0, 0, 0), 3,
				material_init(vec(128, 24, 24)))));
	ft_lstadd_back(&objects->objs, ft_lstnew(SPHERE, sphere_new(vec(10, 0, 0),
				3, material_init(vec(24, 128, 24)))));
	ft_lstadd_back(&objects->objs, ft_lstnew(SPHERE, sphere_new(vec(20, 0, 0),
				3, material_init(vec(24, 24, 128)))));
	/**
		* PLANE
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(PLANE, plane_new(vec(0, -1.5, 0),
				vec(0, 1, 0), material_init(vec(240, 240, 240)))));
	ft_lstadd_back(&objects->objs, ft_lstnew(PLANE, plane_new(vec(-20, 0, 0),
				vec(1, 0, 0), material_init(vec(240, 240, 240)))));
	/**
		* CYLINDER
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(CYLINDER, cylinder_new(vec(30, 0,
					0), vec(0, 1, 0), vec(6, 10, 0), material_init(vec(200, 0,
						0)))));
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