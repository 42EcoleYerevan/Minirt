#include "minirt.h"

t_color	*ft_get_color_from_token(char *token)
{
	t_color	*color;
	char	**rgb;

	rgb = ft_split(token, ',');
	if (!rgb)
		return (NULL);
	color = new_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 1);
	ft_free_arr(rgb);
	return (color);
}

t_vec	ft_get_vector_from_token(char *token)
{
	t_vec 	vector;
	char	**xyz;

	xyz = ft_split(token, ',');
	if (!xyz)
		return ((t_vec){0,0,0,0});
	vector = new_vector(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	ft_free_arr(xyz);
	return (vector);
}

t_figure *ft_last_figure(t_figure *figures)
{
	t_figure *last;

	if (!figures)
		return (NULL);
	last = figures;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_add_figure(t_scene *scene, t_figure *figure)
{
	if (!scene->figure)
		scene->figure = figure;
	else
		ft_last_figure(scene->figure)->next = figure;
}
