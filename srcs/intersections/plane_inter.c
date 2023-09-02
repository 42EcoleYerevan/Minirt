#include "minirt.h"

float	plane_inter(t_vec *o, t_vec *d, t_vec *point, t_vec *normal)
{
	float	denom;
	float	x;

	denom = ft_vec_mult_dot(normal, d);
	if (fabs(denom) > 0)
	{
		x = ft_vec_mult_dot(ft_vec_substr(point, o), normal)
			/ denom;
		if (x > 1e-6)
			return (x);
	}
	return (INFINITY);
}
