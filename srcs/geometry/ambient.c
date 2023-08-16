#include "minirt.h"

t_ambient	*new_ambient(t_color *color, float brightness)
{
	t_ambient	*ambient;

	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->color = color;
	ambient->brightness = brightness;
	return (ambient);
}
