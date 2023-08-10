#include "minirt.h"

int ft_parser(char *filename, t_rt *rt)
{
	char **tokens;

	tokens = ft_tokenizer(filename);
	ft_parse_map(tokens);
	return (0);
}
