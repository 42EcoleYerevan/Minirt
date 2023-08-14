#include "minirt.h"

t_sphere	*new_sphere(t_vec *vec, float radius)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->center = vec;
	new->radius = radius;
	new->next = NULL;
	return (new);
}
