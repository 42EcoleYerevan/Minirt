#include "minirt.h"

t_figure	*new_cylinder(t_vec center, t_vec direction, float radius_height[2], t_color *color)
{
	t_figure	*figure;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		err_exit("err: memory allocating failed.\n");
	cylinder->center = center;
	cylinder->direction = direction;
	if (cylinder->direction.z <= 0)
		cylinder->direction = ft_vec_mult(cylinder->direction, -1);
	cylinder->radius = radius_height[0];
	cylinder->height = radius_height[1];
	figure = new_figure(cylinder, CYLINDER);
	figure->color = color;
	figure->specular = 100;
	figure->next = NULL;
	printf("height = %f, radius = %f\n", cylinder->height, cylinder->radius);
	return (figure);
}
