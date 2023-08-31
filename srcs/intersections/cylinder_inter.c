#include "minirt.h"

float	cylinder_inter(t_vec *o, t_vec *ray, t_cylinder *cylinder)
{
	float a = ray->x * ray->x + ray->y * ray->y;
    float b = 2 * (o->x * ray->x + o->y * ray->y);
    float c = o->x * o->x + o->y * o->y - 1;
	t_vec *s = cylinder->center;
	s++;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return INFINITY;
    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);
    if (t1 > 0 && t1 < t2)
        return t1;
    if (t2 > 0)
        return t2;

    return INFINITY;
}