#include "minirt.h"

float *ft_new_zero_matrix(void)
{
	float *mat;

	mat = (float *)malloc(sizeof(float) * 16);
	if (!mat)
		return (NULL);
	ft_bzero(mat, sizeof(float) * 16);
	return (mat);
}

float	*ft_identity_matrix(void)
{
	float	*mat;

	mat = ft_new_zero_matrix();
	if (!mat)
		return (NULL);
	mat[0] = 1;
	mat[5] = 1;
	mat[10] = 1;
	mat[15] = 1;
	return (mat);
}
