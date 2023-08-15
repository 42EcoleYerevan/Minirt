#include "minirt.h"

t_light	*new_light(t_vec *center, float brightness, t_color *color)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->color = color;
	new->center = center;
	new->brightness = brightness;
	return (new);
}
