#include "minirt.h"

t_objects	*generate(t_sys *sys)
{
	t_objects	*objects;

	objects = ft_calloc(1, sizeof(t_objects));
	objects->num_of_camera = 5;
	objects->num_of_light = 1;
	objects->id_of_camera = 0;
	LOG;
	objects->camera[0] = camera_init(vec(70, 10, 0), vec(-1, 0, 0), 100, sys);
	objects->camera[1] = camera_init(vec(0, 20, -50), vec(0, -0.2, 1), 100,
			sys);
	objects->camera[2] = camera_init(vec(-50, 0, 0), vec(1, 0, 0), 60, sys);
	objects->camera[3] = camera_init(vec(0, 0, 40), vec(0, 0, -1), 80, sys);
	//球の内部
	// objects->camera[3] = camera_init(vec(0, 1, 0), vec(0, 1, 0), 60, sys);
	objects->camera[4] = camera_init(vec(0, 50, 50), vec(0, -1, -1), 50, sys);
	//平面の裏側
	// objects->camera[4] = camera_init(vec(0, -30, 0), vec(0, 1, 0), 90, sys);
	objects->light[0] = light_init(vec(200, 200, 0), color_scaler(vec(255, 255,
					255)), 1, sys);
	objects->ambient = vec_mul(color_scaler(vec(0, 240, 255)), 0.1);
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
		ft_lstadd_back(&objects->objs, ft_lstnew(PLANE, plane_new(vec(-20, 0,
						0),
					vec(1, 0, 0), material_init(vec(240, 240, 240)))));
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(PLANE, plane_new(vec(0, -3, 0),
				vec(0, 1, 0), material_init(vec(240, 240, 240)))));
	/**
		* CYLINDER
		ft_lstadd_back(&objects->objs, ft_lstnew(CYLINDER, cylinder_new(vec(40,
		0,
		0), vec(0, 1, 0), vec(5, 20, 0xDEADBEAF), material_init(vec(200,
		0,
		0)))));
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(CYLINDER, cylinder_new(vec(-15,
					3.5, 0), vec(0, 1, 0), vec(3, 20, 0xDEADBEAF),
				material_init(vec(0, 0, 200)))));
	/**
		* CONE
		ft_lstadd_back(&objects->objs, ft_lstnew(CONE, cone_new(vec(-20, 8.5,
						0),
		vec(0, 1, 0), vec(45, 30, 0xDEADBEAF), material_init(vec(200, 0,
		0)))));
		*/
	/**
		* TRIANGLE
		*/
	ft_lstadd_back(&objects->objs, ft_lstnew(TRIANGLE, triangle_new(vec(-25,
					-1.5, 25), vec(25, -1.5, 25), vec(-25, -1.5, -25),
				material_init(vec(0xF5, 0xF5, 0xDC)))));
	ft_lstadd_back(&objects->objs, ft_lstnew(TRIANGLE, triangle_new(vec(25,
					-1.5, 25), vec(25, -1.5, -25), vec(-25, -1.5, -25),
				material_init(vec(0xF5, 0xF5, 0xDC)))));
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