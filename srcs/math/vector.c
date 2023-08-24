#include "minirt.h"

float	ft_vec_len(t_vec *vec)
{
	float	len;

	len = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	return (len);
}

void	ft_vec_add(t_vec *vec1, t_vec *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
	vec1->z += vec2->z;
	vec1->w += vec2->w;
}

void	ft_vec_mult(t_vec *vec, float mult)
{
	vec->x *= mult;
	vec->y *= mult;
	vec->z *= mult;
	vec->w *= mult;
}

float	ft_vec_mult_vec(t_vec *vec1, t_vec *vec2)
{
	float	res;

	res = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z + vec1->w * vec2->w;
	return (res);
}
