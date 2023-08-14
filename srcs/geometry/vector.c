#include "minirt.h"

t_vec	*new_vector(float x, float y, float z)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec));
	if (!new)
		err_exit("error: memory allocating failed.\n");
	new->x = x;
	new->y = y;
	new->z = z;
	new->w = 1;
	return (new);
}