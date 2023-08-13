#include "minirt.h"

t_light	*new_light(int color, t_vec *center, float brightness)
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

t_ambient	*new_ambient(int color, float bright)
{
	t_ambient	*new;

	new = malloc(sizeof(t_ambient));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->color = color;
	new->bright = bright;
	return (new);
}