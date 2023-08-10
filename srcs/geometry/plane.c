#include "minirt.h"

t_plane	*new_plane(t_vec *center, t_vec *direction, t_color *color)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->center = center;
	plane->direction = direction;
	plane->color = color;
	plane->next = NULL;
	return (plane);
}
