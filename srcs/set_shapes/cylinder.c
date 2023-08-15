#include "minirt.h"

int ft_set_cylinder(char **tokens, t_scene *scene)
{
	t_figure	*figure;
	t_cylinder	*cylinder;
	float		radius_height[2];

	radius_height[0] = ft_atof(tokens[3]);
	radius_height[1] = ft_atof(tokens[4]);
	cylinder = new_cylinder(ft_get_vector_from_token(tokens[1]), \
							ft_get_vector_from_token(tokens[2]), \
							radius_height, \
			   				ft_get_color_from_token(tokens[5]));
	if (!cylinder)
		return (1);
	figure = new_figure(cylinder, CYLINDER);
	if (!figure)
		return (1);
	ft_add_figure(scene, figure);
	return (0);
}
