#include "minirt.h"

int ft_parser(char *filename, t_scene *scene)
{
	char **tokens;

	(void)scene;
	tokens = ft_tokenizer(filename);
	ft_parse_map(tokens, scene);
	return (0);
}
