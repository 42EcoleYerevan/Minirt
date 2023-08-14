#include "minirt.h"

int ft_parser(char *filename, t_scene *scene)
{
	char **lines;

	(void)scene;
	lines = ft_read_scene(filename);
	if (ft_validator(lines))
		err_exit("Error: Invalid scene file\n");
	if (ft_parse_map(lines, scene))
		err_exit("Error: Parse error\n");
	return (0);
}
