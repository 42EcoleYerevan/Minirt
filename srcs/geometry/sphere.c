#include "minirt.h"

t_figure	*new_sphere(t_vec *vec, float radius, t_color *color)
{
	t_figure	*figure;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		err_exit("err: memory allocating failed.\n");
	sphere->center = vec;
	sphere->radius = radius;
	sphere->color = color;
	sphere->specular = 100;
	figure = new_figure(sphere, SPHERE);
	figure->next = NULL;
	return (figure);
}
