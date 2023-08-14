#include "minirt.h"

float	ft_vec_len(t_vec *vec)
{
	float	len;

	len = sqrt(vec_mult_dot(vec, vec));
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

void	ft_vec_mult_vec(t_vec *vec1, t_vec *vec2)
{
	vec1->x *= vec2->x;
	vec1->y *= vec2->y;
	vec1->z *= vec2->z;
	vec1->w *= vec2->w;
}

void	ft_vec_mult_mat(t_vec *vec, t_mat *mat)
{
	t_vec tmp;

	tmp.x = vec->x * mat->x.x + vec->y * mat->y.x + vec->z * mat->z.x + vec->w * mat->w.x;
	tmp.y = vec->x * mat->x.y + vec->y * mat->y.y + vec->z * mat->z.y + vec->w * mat->w.y;
	tmp.z = vec->x * mat->x.z + vec->y * mat->y.z + vec->z * mat->z.z + vec->w * mat->w.z;
	tmp.w = vec->x * mat->x.w + vec->y * mat->y.w + vec->z * mat->z.w + vec->w * mat->w.w;
	*vec = tmp;
}

void	ft_mat_mult_mat(t_mat *mat1, t_mat *mat2)
{
	t_mat tmp;

	tmp.x.x = mat1->x.x * mat2->x.x + mat1->y.x * mat2->x.y + mat1->z.x * mat2->x.z + mat1->w.x * mat2->x.w;
	tmp.x.y = mat1->x.y * mat2->x.x + mat1->y.y * mat2->x.y + mat1->z.y * mat2->x.z + mat1->w.y * mat2->x.w;
	tmp.x.z = mat1->x.z * mat2->x.x + mat1->y.z * mat2->x.y + mat1->z.z * mat2->x.z + mat1->w.z * mat2->x.w;
	tmp.x.w = mat1->x.w * mat2->x.x + mat1->y.w * mat2->x.y + mat1->z.w * mat2->x.z + mat1->w.w * mat2->x.w;
	tmp.y.x = mat1->x.x * mat2->y.x + mat1->y.x * mat2->y.y + mat1->z.x * mat2->y.z + mat1->w.x * mat2->y.w;
	tmp.y.y = mat1->x.y * mat2->y.x + mat1->y.y * mat2->y.y + mat1->z.y * mat2->y.z + mat1->w.y * mat2->y.w;
	tmp.y.z = mat1->x.z * mat2->y.x + mat1->y.z * mat2->y.y + mat1->z.z * mat2->y.z + mat1->w.z * mat2->y.w;
	tmp.y.w = mat1->x.w * mat2->y.x + mat1->y.w * mat2->y.y + mat1->z.w * mat2->y.z + mat1->w.w * mat2->y.w;
	tmp.z.x = mat1->x.x * mat2->z.x + mat1->y.x * mat2->z.y + mat1->z.x * mat2->z.z + mat1->w.x * mat2->z.w;
	tmp.z.y = mat1->x.y * mat2->z.x + mat1->y.y * mat2->z.y;
	(void)tmp;
}

t_vec	*vec_substr(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (res);
}

float	vec_mult_dot(t_vec *vec1, t_vec *vec2)
{
	float	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}
void	vec_norm(t_vec *vec)
{
	float	len;

	len = ft_vec_len(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}
