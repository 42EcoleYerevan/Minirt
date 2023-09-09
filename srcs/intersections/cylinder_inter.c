#include "../../includes/minirt.h"

int	quadratic_cylinder(float t[2], t_vec vecs[2], t_cylinder *cy)
{
	t_vec	v1;
	t_vec	v2;
	t_abc	abc;

	v1 = ft_vec_mult(cy->direction, ft_vec_mult_dot(vecs[0], cy->direction));
	v1 = ft_vec_substr(vecs[0], v1);
	v2 = ft_vec_mult(cy->direction, ft_vec_mult_dot(ft_vec_substr(vecs[1], cy->center), cy->direction));
	v2 = ft_vec_substr(ft_vec_substr(vecs[1], cy->center), v2);
	abc.a = ft_vec_mult_dot(v1, v1);
	abc.b = 2 * ft_vec_mult_dot(v1, v2);
	abc.c = ft_vec_mult_dot(v2, v2) - pow(cy->radius, 2);
	abc.disc = abc.b * abc.b - (4 * abc.a * abc.c);
	if (abc.disc < 0)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (0);
	}
	t[0] = (-abc.b + sqrt(abc.disc)) / (2 * abc.a);
	t[1] = (-abc.b - sqrt(abc.disc)) / (2 * abc.a);
	if (t[0] < EPSILON && t[1] < EPSILON)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (0);
	}
	return (1);
}

float	choose_cylinder_dist(float t[2], t_cylinder *cy)
{
	float	dist;
	float 	t1;

	if ((cy->dist[0] >= 0 && cy->dist[0] <= cy->height && t[0] > EPSILON)
		&& (cy->dist[1] >= 0 && cy->dist[1] <= cy->height && t[1] > EPSILON))
	{
		dist = cy->dist[1];
		t1 = t[1];
		if (t[0] < t[1])
		{
			dist = cy->dist[0];
			t1 = t[0];
		}
	}
	else if (cy->dist[0] >= 0 && cy->dist[0] <= cy->height && t[0] > EPSILON)
	{
		dist = cy->dist[0];
		t1 = t[0];
	}
	else
	{
		dist = cy->dist[1];
		t1 = t[1];
	}
	t[0] = t1;
	return (dist);
}

t_vec	calc_cylinder_normal(float t[2], t_vec vecs[2], t_cylinder *cylinder)
{
	float	dist;

	dist = choose_cylinder_dist(t, cylinder);
	return ft_vec_norm(ft_vec_substr(ft_vec_substr(ft_vec_mult(vecs[0], t[0]), ft_vec_mult(cylinder->direction, dist)),
							  ft_vec_substr(cylinder->center, vecs[1])));
}

float calc_cylinder_dist(t_cylinder *cylinder, t_vec vecs[2], float t)
{
	float	dist;

	dist = ft_vec_mult_dot(cylinder->direction,
						   ft_vec_substr(ft_vec_mult(vecs[0],t),
										 ft_vec_substr(cylinder->center, vecs[1])));
	return (dist);
}

float calc_side_inter(t_vec vecs[2],t_vec *normal, t_cylinder *cylinder)
{
	float	t[2];

	if (quadratic_cylinder(t, vecs, cylinder) == 0)
		return (INFINITY);
	cylinder->dist[0] = calc_cylinder_dist(cylinder, vecs, t[0]);
	cylinder->dist[1] = calc_cylinder_dist(cylinder, vecs, t[1]);
	if (!((cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height && t[0] > EPSILON)
		|| (cylinder->dist[1] >= 0 && cylinder->dist[1] <= cylinder->height && t[0] > EPSILON)))
		return (INFINITY);
	*normal = calc_cylinder_normal(t, vecs, cylinder);
	return (t[0]);
}

float	calc_caps_inter(t_vec vecs[2], t_cylinder *cy)
{
	float	inter[2];
	t_vec	v[2];
	t_vec	center;

	center = ft_vec_add(cy->center, ft_vec_mult(cy->direction, cy->height));
	inter[0] = plane_inter(vecs[1], vecs[0], cy->center, cy->direction);
	inter[1] = plane_inter(vecs[1], vecs[0], center, cy->direction);
	if ((inter[0] < INFINITY && inter[0] > EPSILON) || (inter[1] < INFINITY && inter[1] > EPSILON))
	{
		v[0] = ft_vec_add(vecs[1], ft_vec_mult(vecs[0], inter[0]));
		v[1] = ft_vec_add(vecs[1], ft_vec_mult(vecs[0], inter[1]));
		if ((inter[0] < INFINITY && ft_vec_dist(v[0], cy->center) <= cy->radius)
			&& (inter[1] < INFINITY && ft_vec_dist(v[1], center) <= cy->radius))
		{
			 if (inter[0] < inter[1])
				 return (inter[0]);
			 return (inter[1]);
		}
		if (inter[0] < INFINITY && ft_vec_dist(v[0], cy->center) <= cy->radius)
			return (inter[0]);
		if (inter[1] < INFINITY && ft_vec_dist(v[1], center) <= cy->radius)
			return (inter[1]);
		return (INFINITY);
	}
	return (INFINITY);
}

float	cylinder_inter(t_vec o, t_vec d, t_figure *figure) {
	float side_inter;
	float caps_inter;
	t_vec vecs[2];
	t_vec normal;

	vecs[0] = d;
	vecs[1] = o;
	side_inter = calc_side_inter(vecs, &normal, (t_cylinder *)figure->data);
	caps_inter = calc_caps_inter(vecs, (t_cylinder *)figure->data);
	if (side_inter < INFINITY || caps_inter < INFINITY)
	{
		if (side_inter < caps_inter && side_inter > EPSILON)
		{
			figure->normal = normal;
			return (side_inter);
		}
		if (caps_inter < INFINITY && caps_inter > EPSILON)
		{
			figure->normal = ((t_cylinder *)figure->data)->direction;
			if (figure->normal.z <= 0)
				figure->normal = ft_vec_mult(figure->normal, -1);
			// printf("x = %f y = %f z = %f\n", figure->normal.x, figure->normal.y, figure->normal.z);
			// printf("inter = %f\n", caps_inter);
			return (caps_inter);
		}
	}
	return (INFINITY);
}