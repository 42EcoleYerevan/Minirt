#include "minirt.h"

int ft_parser(char *filename)
{
	char **tokens;

	tokens = ft_tokenizer(filename);
	ft_parse_map(tokens);
	return (0);
}
