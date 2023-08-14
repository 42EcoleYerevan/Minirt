#include "minirt.h"

t_color	*ft_get_color_from_token(char *token)
{
	t_color	*color;
	char	**rgb;

	rgb = ft_split(token, ',');
	if (!rgb)
		return (NULL);
	color = new_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	ft_free_arr(rgb);
	return (color);
}

t_vec	*ft_get_vector_from_token(char *token)
{
	t_vec 	*vector;
	char	**xyz;

	xyz = ft_split(token, ',');
	if (!xyz)
		return (NULL);
	vector = new_vector(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	ft_free_arr(xyz);
	return (vector);
}
