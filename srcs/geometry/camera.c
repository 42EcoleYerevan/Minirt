#include "minirt.h"

t_camera	*new_camera(t_vec *origin, t_vec *direction, float fov)
{
	t_camera	*new;

	if (!origin || !direction)
		return (NULL);
	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	new->origin = origin;
	new->direction = direction;
	new->up = new_vector(0, 1, 0);
	new->right = new_vector(1, 0, 0);
	new->fov = fov;
	return	(new);
}
