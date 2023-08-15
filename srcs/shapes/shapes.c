#include "minirt.h"

int	ft_set_shape(char **tokens, t_scene *scene)
{
	puts(tokens[0]);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (ft_set_ambient(tokens, scene));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (ft_set_camera(tokens, scene));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (ft_set_light(tokens, scene));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (ft_set_sphere(tokens, scene));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (ft_set_plane(tokens, scene));
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (ft_set_cylinder(tokens, scene));
	else
		return (1);
	return (0);
}
