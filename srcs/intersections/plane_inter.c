#include "minirt.h"

float	plane_inter(t_vec *o, t_vec *d, t_vec *point, t_vec *normal)
{
	float	denom;
	float	x;
	t_vec	*tmp;

	denom = ft_vec_mult_dot(normal, d);
	if (denom == 0)
		return (INFINITY);
	tmp = ft_vec_substr(point, o);
	x = ft_vec_mult_dot(tmp, normal) / denom;
	if (x > 0)
		return (x);
	return (INFINITY);
}
