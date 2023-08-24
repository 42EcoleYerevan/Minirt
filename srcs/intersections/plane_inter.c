#include "minirt.h"

float	plane_inter(t_vec *o, t_vec *d, t_plane *plane)
{
	float	a;

	a = ft_vec_mult_dot(plane->normal, d);
	if (a == 0)
		return (INFINITY);
	a = ft_vec_mult_dot(ft_vec_substr(plane->point, o), plane->normal) / a;
	if (a < 0.001)
		return (INFINITY);
	return (a);
}
