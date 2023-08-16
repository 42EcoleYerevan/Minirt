#include "minirt.h"

void	ft_light_last_add(t_scene *scene, t_light *light);
t_light	*ft_last_light(t_scene *scene);

int ft_set_light(char **tokens, t_scene *scene)
{
	t_light *light;
	t_vec	*center;
	t_color	*color;

	if (!tokens || !scene)
		return (1);
	center = ft_get_vector_from_token(tokens[1]);
	color = ft_get_color_from_token(tokens[3]);
	if (!center || !color)
		return (1);
	light = new_light(center, ft_atof(tokens[2]), color);
	ft_light_last_add(scene, light);
	return (0);
}

void	ft_light_last_add(t_scene *scene, t_light *light)
{
	if (!scene->light)
		scene->light = light;
	else
		ft_last_light(scene)->next = light;
}

t_light	*ft_last_light(t_scene *scene)
{
	t_light	*last;

	if (!scene->light)
		return (NULL);
	last = scene->light;
	while (last->next)
		last = last->next;
	return (last);
}
