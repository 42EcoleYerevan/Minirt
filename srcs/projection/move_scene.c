#include "minirt.h"

void	ft_xrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_xrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	free(matrix);
}

void	ft_yrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_yrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	free(matrix);
}

void	ft_zrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_zrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	free(matrix);
}
