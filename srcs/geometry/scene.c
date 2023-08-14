#include "minirt.h"

t_scene		*new_scene(float width, float height)
{
	t_scene		*new;

	new = malloc(sizeof(t_scene));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->width = width;
	new->height = height;
	new->cams = NULL;
	new->ambient = NULL;
	new->light = NULL;
	new->figure = NULL;
	return (new);	
}
