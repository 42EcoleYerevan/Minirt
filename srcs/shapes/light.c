#include "minirt.h"

int ft_set_light(char **tokens, t_scene *scene)
{
	t_light *light;
	t_vec	*center;
	t_color	*color;

	light = NULL;
	if (!tokens || !scene)
		return (1);
	center = ft_get_vector_from_token(tokens[1]);
	color = ft_get_color_from_token(tokens[3]);
	if (!center || !color)
		return (1);
	light = new_light(center, ft_atof(tokens[2]), color);
	return (0);
}
