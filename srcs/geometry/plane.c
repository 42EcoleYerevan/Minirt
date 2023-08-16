#include "geometry.h"
#include "minirt.h"

t_figure	*new_plane(t_vec *center, t_vec *direction, t_color *color)
{
	t_figure	*figure;
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->center = center;
	plane->direction = direction;
	plane->color = color;
	plane->next = NULL;
	figure = new_figure(plane, PLANE);
	return (figure);
}
