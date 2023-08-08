#include "minirt.h"

t_vec	*new_vector(float x, float y, float z)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec));
	if (!new)
		exit_err("error: memory allocating failed.\n");
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

float	vec_len(t_vec *vec)
{
	float	result;

	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (result);
}

void	vec_norm(t_vec *vec)
{
	float	len;

	len = vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}