#include "minirt.h"

t_camera	*new_camera(t_vec *origin, t_vec *direction, float fov)
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->origin = origin;
	new->direction = direction;
	new->fov = fov;
	return	(new);
}