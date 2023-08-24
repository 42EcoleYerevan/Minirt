#include "minirt.h"

static void	ft_move_lights(t_light *light, t_vec *vec);

void	ft_xmove_scene(t_scene *scene, float x)
{
	t_vec		*to;

	to = new_vector(x, 0, 0);
	ft_move_objects(scene, to);
	ft_move_lights(scene->light, to);
	free(to);
}

void	ft_ymove_scene(t_scene *scene, float y)
{
	t_vec		*to;

	to = new_vector(0, y, 0);
	ft_move_objects(scene, to);
	ft_move_lights(scene->light, to);
	free(to);
}

void	ft_zmove_scene(t_scene *scene, float z)
{
	t_vec		*to;

	to = new_vector(0, 0, z);
	ft_move_objects(scene, to);
	ft_move_lights(scene->light, to);
	free(to);
}

static void	ft_move_lights(t_light *light, t_vec *vec)
{
	while (light)
	{
		ft_vec_add(light->center, vec);
		light = light->next;
	}
}
