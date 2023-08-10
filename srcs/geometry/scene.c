#include "minirt.h"

t_scene		*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene		*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->cams = cam;
	new->sphere = sphere;
	new->width = 0;
	new->height = 0;
	return (new);	
}