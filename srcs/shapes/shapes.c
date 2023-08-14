#include "minirt.h"

int	ft_set_shape(char **tokens, t_scene *scene)
{
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (ft_set_ambient(tokens, scene));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (ft_set_camera(tokens, scene));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (ft_set_light(tokens, scene));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (ft_set_sphere(tokens, scene));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		printf("plane\n");
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		printf("cylinder\n");
	else
		return (1);
	(void)scene;
	return (0);
}
