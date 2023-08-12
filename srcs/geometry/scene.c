#include "minirt.h"

t_scene		*new_scene(t_camera *cam, float width, float height)
{
	t_scene		*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->cams = cam;
	new->width = width;
	new->height = height;
	return (new);	
}
