#include "minirt.h"

t_cylinder *new_cylinder(t_vec *center, t_vec *direction, float radius_height[2], t_color *color)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->center = center;
	cylinder->direction = direction;
	cylinder->radius = radius_height[0];
	cylinder->height = radius_height[1];
	cylinder->color = color;
	cylinder->next = NULL;
	return (cylinder);
}
