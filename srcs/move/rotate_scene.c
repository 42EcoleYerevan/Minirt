#include "minirt.h"

static void	ft_rotate_lights(t_light *light, float *matrix);

void	ft_xrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_xrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
	free(matrix);
}

void	ft_yrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_yrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
	free(matrix);
}

void	ft_zrotate_scene(t_scene *scene, float angle)
{
	float	*matrix;

	matrix = ft_zrotation_matrix(angle);
	if (!matrix)
		return ;
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
	free(matrix);
}

static void	ft_rotate_lights(t_light *light, float *matrix)
{
	while (light)
	{
		ft_vec_mult_mat(light->center, matrix);
		light = light->next;
	}
}
