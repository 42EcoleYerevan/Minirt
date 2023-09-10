#include "minirt.h"

void	ft_xrotate_scene(t_scene *scene, float angle);
void	ft_yrotate_scene(t_scene *scene, float angle);
void	ft_zrotate_scene(t_scene *scene, float angle);
static void	ft_rotate_lights(t_light *light, t_matrix matrix);

void	ft_xrotate_scene(t_scene *scene, float angle)
{
	t_matrix	matrix;

	matrix = ft_xrotate_matrix(angle);
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
}

void	ft_yrotate_scene(t_scene *scene, float angle)
{
	t_matrix	matrix;

	matrix = ft_yrotate_matrix(angle);
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
}

void	ft_zrotate_scene(t_scene *scene, float angle)
{
	t_matrix	matrix;

	matrix = ft_zrotate_matrix(angle);
	ft_rotate_objects(scene, matrix);
	ft_rotate_lights(scene->light, matrix);
}

static void	ft_rotate_lights(t_light *light, t_matrix matrix)
{
	while (light)
	{
		light->center = ft_vec_mult_mat(light->center, matrix);
		light = light->next;
	}
}
