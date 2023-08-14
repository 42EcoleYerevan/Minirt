#include "minirt.h"

t_ambient	*new_ambient(t_color *color, float ratio)
{
	t_ambient	*ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->color = color;
	ambient->brightness = ratio;
	return (ambient);
}
