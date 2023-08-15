#include "minirt.h"

int	ft_set_plane(char **tokens, t_scene *scene)
{
	t_figure	*plane;
	t_vec		*center;
	t_vec		*direction;
	t_color		*color;

	center = ft_get_vector_from_token(tokens[1]);
	direction = ft_get_vector_from_token(tokens[2]);
	color = ft_get_color_from_token(tokens[3]);
	plane = new_plane(center, direction, color);
	ft_add_figure(scene, plane);
	return (0);
}
