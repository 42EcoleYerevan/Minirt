#include "minirt.h"

float	sphere_inter(t_vec *o, t_vec *ray, t_sphere *sphere)
{
	float	a;
	float	b;
	float	c;
	float	discr;
	float	t1;
	float	t2;
	t_vec	*cam_sphere;

	a = vec_mult_dot(ray, ray);
	cam_sphere = vec_substr(o, sphere->center);
	b = 2 * vec_mult_dot(cam_sphere, ray);
	c = vec_mult_dot(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = b * b - (4 * a * c);
	if (discr < 0)
		return (0);
	t1 = (-b - sqrt(discr)) / (2 * a);
	t2 = (-b + sqrt(discr)) / (2 * a);
	if (t1 <= 0 && t2 <= 0)
		return (0);
	if (t1 > t2)
		return (t2);
	return (t1);
}