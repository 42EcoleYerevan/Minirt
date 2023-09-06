#include "geometry.h"
#include "minirt.h"

t_vec	normal_check_and_reverse(t_vec normal)
{
	if (normal.x < 0)
		normal.x *= -1;
	if (normal.y < 0)
		normal.y *= -1;
	if (normal.z < 0)
		normal.z *= -1;
	return (normal);
}

t_figure	*new_plane(t_vec point, t_vec normal, t_color *color)
{
	t_figure	*figure;
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		err_exit("err: memory allocating failed.\n");
	plane->point = point;
	plane->normal = normal;
	plane->normal = normal_check_and_reverse(plane->normal);
	figure = new_figure(plane, PLANE);
	figure->color = color;
	figure->specular = 100;
	figure->next = NULL;
	// printf("x - %f, y - %f, z - %f", plane->normal.x, plane->normal.y, plane->normal.z);
	return (figure);
}
