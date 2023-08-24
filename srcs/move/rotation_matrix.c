#include "minirt.h"

float *ft_xrotation_matrix(float alfa)
{
	float *matrix;

	matrix = ft_identity_matrix();
	if (!matrix)
		return (NULL);
	matrix[5] = cos(alfa);
	matrix[6] = -sin(alfa);
	matrix[9] = sin(alfa);
	matrix[10] = cos(alfa);
	return (matrix);
}

float *ft_yrotation_matrix(float alfa)
{
	float *matrix;

	matrix = ft_identity_matrix();
	if (!matrix)
		return (NULL);
	matrix[0] = cos(alfa);
	matrix[2] = sin(alfa);
	matrix[8] = -sin(alfa);
	matrix[10] = cos(alfa);
	return (matrix);
}

float *ft_zrotation_matrix(float alfa)
{
	float *matrix;

	matrix = ft_identity_matrix();
	if (!matrix)
		return (NULL);
	matrix[0] = cos(alfa);
	matrix[1] = -sin(alfa);
	matrix[4] = sin(alfa);
	matrix[5] = cos(alfa);
	return (matrix);
}
