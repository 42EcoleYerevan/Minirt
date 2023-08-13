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
	return (new);
}

void	vec_norm(t_vec *vec)
{
	float	len;

	len = ft_vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}