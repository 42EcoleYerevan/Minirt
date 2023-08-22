#include "minirt.h"

float	plane_inter(t_vec *o, t_vec *d, t_plane *plane)
{
	float	vd;
	float	t;
	t_vec	*v0;

	vd = ft_vec_mult_vec(plane->normal, d);
	if (fabs(vd) < 1e-6)
        return (0);
	v0 = ft_vec_substr(plane->point, o);
	t = ft_vec_mult_dot(v0, plane->normal) / vd;
	free(v0);
	if (t > 0)
		return (t);
	return (0);
}