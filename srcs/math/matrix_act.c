#include "geometry.h"
#include "minirt.h"

t_matrix	ft_mat_mult(t_matrix mat1, t_matrix mat2)
{
	t_matrix	out_mat;
	int row;
	int col;
	int k;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			k = 0;
			out_mat.m[row * 4 + col] = 0;
			while (k < 4)
			{
				out_mat.m[row * 4 + col] += mat1.m[row * 4 + k] * \
											mat2.m[k * 4 + col];
				k++;
			}
			col++;
		}
	}
	return (out_mat);
}

t_matrix	ft_mat_sub(t_matrix mat1, t_matrix mat2)
{
	t_matrix	out_mat;
	int i;

	i = 0;
	while (i < 16)
	{
		out_mat.m[i] = mat1.m[i] - mat2.m[i];
		i++;
	}
	return (out_mat);
}

t_matrix	ft_mat_add(t_matrix mat1, t_matrix mat2)
{
	t_matrix	out_mat;
	int i;

	i = 0;
	while (i < 16)
	{
		out_mat.m[i] = mat1.m[i] + mat2.m[i];
		i++;
	}
	return (out_mat);
}

t_vec	ft_vec_mult_mat(t_vec vec, t_matrix mat)
{
	t_vec	out_vec;

	out_vec.x = vec.x * mat.m[0] + vec.y * mat.m[4] + vec.z * mat.m[8] + \
				vec.w * mat.m[12];
	out_vec.y = vec.x * mat.m[1] + vec.y * mat.m[5] + vec.z * mat.m[9] + \
				vec.w * mat.m[13];
	out_vec.z = vec.x * mat.m[2] + vec.y * mat.m[6] + vec.z * mat.m[10] + \
				vec.w * mat.m[14];
	out_vec.w = vec.x * mat.m[3] + vec.y * mat.m[7] + vec.z * mat.m[11] + \
				vec.w * mat.m[15];
	return (out_vec);
}
