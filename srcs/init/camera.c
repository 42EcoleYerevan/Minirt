#include "minirt.h"

t_camera	*new_camera(t_vec origin, t_vec direction, float fov)
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	new->origin = origin;
	new->direction = direction;
	new->right = new_vector(1, 0, 0);
	new->fov = fov;
	new->near = 0.1;
	new->far = 1000;
	return	(new);
}
