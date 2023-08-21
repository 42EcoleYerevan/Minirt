#include "minirt.h"

static float	*ft_translation_matrix(t_camera *camera);
static float	*ft_orientation_matrix(t_camera *camera);

float	*ft_view_matrix(t_camera *camera)
{
	float	*matrix;
	float	*translation;
	float	*orientation;

	translation = ft_translation_matrix(camera);
	orientation = ft_orientation_matrix(camera);
	if (!translation)
		return (NULL);
	if (!orientation)
	{
		free(translation);
		return (NULL);
	}
	matrix = ft_mat_mult(translation, orientation);
	free(translation);
	free(orientation);
	return (matrix);
}

static float	*ft_translation_matrix(t_camera *camera)
{
	float	*matrix;

	matrix = ft_identity_matrix();
	if (!matrix)
		return (NULL);
	matrix[3] = camera->origin->x;
	matrix[7] = camera->origin->y;
	matrix[11] = camera->origin->z;
	return (matrix);
}

static float	*ft_orientation_matrix(t_camera *camera)
{
	float	*matrix;
	t_vec	*up;

	matrix = ft_identity_matrix();
	up = ft_vec_cross(camera->direction, camera->right);
	if (!matrix)
		return (NULL);
	if (!up)
	{
		free(matrix);
		return (NULL);
	}
	matrix[0] = camera->right->x;
	matrix[1] = camera->right->y;
	matrix[2] = camera->right->z;
	matrix[4] = up->x;
	matrix[5] = up->y;
	matrix[6] = up->z;
	matrix[8] = -camera->direction->x;
	matrix[9] = -camera->direction->y;
	matrix[10] = -camera->direction->z;
	free(up);
	return (matrix);
}
