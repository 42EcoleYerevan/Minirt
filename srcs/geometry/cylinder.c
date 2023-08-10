#include "minirt.h"

t_cylinder *new_cylinder(t_vec *center, t_vec *direction, float radius, float height, t_color *color)
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->center = center;
	cylinder->direction = direction;
	cylinder->radius = radius;
	cylinder->height = height;
	cylinder->color = color;
	cylinder->next = NULL;
	return (cylinder);
}
