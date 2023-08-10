#include "minirt.h"

t_cylinder	*new_cylinder(t_vec *center, float radius, float width, float height)
{
	t_cylinder	*new;

	new = malloc(sizeof(t_cylinder));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->center = center;
	new->width = width;
	new->height = height;
	new->radius = radius;
	return (new);
}
