#include "geometry.h"
#include "minirt.h"

t_figure	*new_plane(t_vec *point, t_vec *normal, t_color *color)
{
	t_figure	*figure;
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		err_exit("err: memory allocating failed.\n");
	plane->point = point;
	plane->normal = normal;
	plane->color = color;
	plane->specular = 0;
	figure = new_figure(plane, PLANE);
	figure->next = NULL;
	return (figure);
}
