#include "minirt.h"

int	ft_set_camera(char **tokens, t_scene *scene)
{
	t_camera	*camera;
	t_vec	center;
	t_vec	direction;
	float	fov;

	if (!tokens || !scene)
		return (1);
	center = ft_get_vector_from_token(tokens[1]);
	direction = ft_get_vector_from_token(tokens[2]);
	fov = ft_atof(tokens[3]);
	camera = new_camera(center, direction, fov);
	if (!camera)
		return (1);
	scene->cams = camera;
	return (0);
}
