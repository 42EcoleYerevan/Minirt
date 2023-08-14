#include "minirt.h"

t_vec *ft_parse_vector(char *str)
{
	t_vec	*vector;
	char	**tokens;

	if (!str)
		return (NULL);
	tokens = ft_split(str, ',');
	if (!tokens)
		return (NULL);
	vector = new_vector(ft_atof(tokens[0]), \
						ft_atof(tokens[1]), \
						ft_atof(tokens[2]));
	if (!vector)
		return (NULL);
	ft_free_arr(tokens);
	return (vector);
}
