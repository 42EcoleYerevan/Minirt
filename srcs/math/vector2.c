#include "minirt.h"

t_vec	*ft_vec_substr(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (res);
}

float	ft_vec_mult_dot(t_vec *vec1, t_vec *vec2)
{
	float	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}
void	ft_vec_norm(t_vec *vec)
{
	float	len;

	len = ft_vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

t_vec	*ft_vec_cross(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = new_vector(vec1->y * vec2->z - vec1->z * vec2->y,
			vec1->z * vec2->x - vec1->x * vec2->z,
			vec1->x * vec2->y - vec1->y * vec2->x);
	return (res);
}
