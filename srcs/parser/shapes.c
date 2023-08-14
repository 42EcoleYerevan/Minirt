#include "minirt.h"

int	ft_set_shape(char **tokens, t_scene *scene)
{
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		printf("ambient light\n");
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		printf("camera\n");
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		printf("light\n");
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		printf("sphere\n");
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		printf("plane\n");
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		printf("cylinder\n");
	else
		return (1);
	(void)scene;
	return (0);
}

int ft_set_sphere(char **tokens, t_scene *scene)
{
	t_sphere *sphere;

	sphere = NULL;
	if (!tokens || !scene)
		return (1);
	return (0);
}
