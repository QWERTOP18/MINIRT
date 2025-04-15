#include "console.h"

void	log_camera(t_camera *camera, int id)
{
	printf(YELLOW BOLD "--- camera [%d] -------------------\n" RESET, id);
	log_vec_inline("pos", camera->pos);
	log_vec_inline("dir", camera->dir);
	printf("fov: %.2f\n", camera->fov);
	printf(YELLOW BOLD "----------------------------------\n" RESET);
}
