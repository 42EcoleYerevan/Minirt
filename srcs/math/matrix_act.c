#include "minirt.h"

float	*ft_mat_mult(float *mat1, float *mat2)
{
	float *mat3;
	int row;
	int col;
	int k;

	mat3 = malloc(sizeof(float) * 16);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat3[row * 4 + col] = 0;
			k = 0;
			while (k < 4)
			{
				mat3[row * 4 + col] += mat1[row * 4 + k] * mat2[k * 4 + col];
				k++;
			}
			col++;
		}
		row++;
	}
	return (mat3);
}

float *ft_mat_sub(float *mat1, float *mat2)
{
	float *mat3;
	int i;

	mat3 = malloc(sizeof(float) * 16);
	i = 0;
	while (i < 16)
	{
		mat3[i] = mat1[i] - mat2[i];
		i++;
	}
	return (mat3);
}

float *ft_mat_add(float *mat1, float *mat2)
{
	float *mat3;
	int i;

	mat3 = malloc(sizeof(float) * 16);
	i = 0;
	while (i < 16)
	{
		mat3[i] = mat1[i] + mat2[i];
		i++;
	}
	return (mat3);
}

void	ft_vec_mult_mat(t_vec *vec, float *mat)
{
	vec->x = vec->x * mat[0] + vec->y * mat[4] + vec->z * mat[8] + \
			 vec->w * mat[12];
	vec->y = vec->x * mat[1] + vec->y * mat[5] + vec->z * mat[9] + \
			 vec->w * mat[13];
	vec->z = vec->x * mat[2] + vec->y * mat[6] + vec->z * mat[10] + \
			 vec->w * mat[14];
	/* vec->w = vec->x * mat[3] + vec->y * mat[7] + vec->z * mat[11] + \ */
	/* 		 vec->w * mat[15]; */
}

t_vec	*ft_vec_mult_mat_new(t_vec *vec, float *mat)
{
	t_vec *new_vec;

	new_vec = malloc(sizeof(t_vec));
	new_vec->x = vec->x * mat[0] + vec->y * mat[4] + vec->z * mat[8] + \
				 vec->w * mat[12];
	new_vec->y = vec->x * mat[1] + vec->y * mat[5] + vec->z * mat[9] + \
				 vec->w * mat[13];
	new_vec->z = vec->x * mat[2] + vec->y * mat[6] + vec->z * mat[10] + \
				 vec->w * mat[14];
	/* new_vec->w = vec->x * mat[3] + vec->y * mat[7] + vec->z * mat[11] + \ */
	/* 			 vec->w * mat[15]; */
	return (new_vec);
}
