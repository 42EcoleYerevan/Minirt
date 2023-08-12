#include "minirt.h"

float	sphere_inter(t_camera *cam, t_vec *ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_2;
	t_vec	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vec_substr(cam->origin, sphere->center);
	b = 2 * (vec_mult_dot(cam_sphere, ray));
	c = vec_mult_dot(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr) / 2);
	dist_2 = ((b * (-1)) + sqrt(discr) / 2);
	(void)dist_2;
	printf("dist1 = %f, dist2 = %f ", dist_1, dist_2);
	if (dist_1 > 0)
		return (dist_1);
	return (0);
}