#include "minirt.h"

float	sphere_inter(t_vec o, t_vec ray, t_sphere *sphere)
{
	t_abc	abc;
	float	t1;
	t_vec	cam_sphere;

	abc.a = ft_vec_mult_dot(ray, ray);
	cam_sphere = ft_vec_substr(o, sphere->center);
	abc.b = 2 * ft_vec_mult_dot(cam_sphere, ray);
	abc.c = ft_vec_mult_dot(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	abc.disc = abc.b * abc.b - (4 * abc.a * abc.c);
	if (abc.disc < 0)
		return (0);
	t1 = (-abc.b - sqrt(abc.disc)) / (2 * abc.a);
	if (t1 <= 0)
		return (0);
	return (t1);
}
