#include "minirt.h"

t_light	*new_light(t_color *color, t_vec *center, float brightness)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->color = color;
	new->center = center;
	new->brightness = brightness;
	return (new);
}

t_ambient	*new_ambient(t_color *color, float ratio)
{
	t_ambient	*new;

	new = malloc(sizeof(t_ambient));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->color = color;
	new->brightness = ratio;
	return (new);
}