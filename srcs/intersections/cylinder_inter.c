#include "minirt.h"

int quadratic_solve(t_vec *v1, t_vec *v2, t_cylinder *cylinder, float t[2])
{
	t_abc   abc;

	abc.a = ft_vec_mult_dot(v1, v1);
	abc.b = 2 * ft_vec_mult_dot(v1, v2);
	abc.c = ft_vec_mult_dot(v2, v2) - cylinder->radius * cylinder->radius;
	abc.disc = abc.b * abc.b - (4 * abc.a * abc.c);
	if (abc.disc < 0)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (0);
	}
	t[0] = (-abc.b + sqrt(abc.disc)) / (2 * abc.a);
	t[1] = (-abc.b - sqrt(abc.disc)) / (2 * abc.a);
	if (t[0] < 0.00001 && t[1] < 0.00001)
	{
		t[0] = INFINITY;
		t[1] = INFINITY;
		return (0);
	}
	return (1);
}

int cylinder_quadratic(float t[2], t_cylinder *cylinder, t_vec *vecs[2])
{
	t_vec   *v1;
	t_vec   *v2;
	t_vec   *tmp[2];

	v1 = ft_vec_dup(cylinder->direction);
	ft_vec_mult(v1, ft_vec_mult_dot(vecs[0], cylinder->direction));
	tmp[0] = v1;
	v1 = ft_vec_substr(vecs[0], v1);
	free(tmp[0]);
	tmp[0] = ft_vec_substr(vecs[1], cylinder->center);
	v2 = ft_vec_dup(cylinder->direction);
	ft_vec_mult(v2, ft_vec_mult_dot(tmp[0], cylinder->direction));
	free(tmp[0]);
	tmp[0] = v2;
	tmp[1] = ft_vec_substr(vecs[1], cylinder->center);
	v2 = ft_vec_substr(tmp[1], v2);
	free(tmp[0]);
	free(tmp[1]);
	return (quadratic_solve(v1, v2, cylinder, t));
}

float   find_side_dist(float t[2], t_cylinder *cylinder)
{
	float   dist;
	float   t1;

	if ((cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height && t[0] > 0.00001) && (cylinder->dist[1] >= 0 && cylinder->dist[1] <= cylinder->height && t[1] > 0.00001))
	{
		dist = cylinder->dist[1];
		if (t[0] < t[1])
			dist = cylinder->dist[0];
		t1 = t[1];
		if (t[0] < t[1])
			t1 = t[0];
	}
	else if (cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height && t[0] > 0.00001)
	{
		dist = cylinder->dist[0];
		t1 = t[0];
	}
	else
	{
		dist = cylinder->dist[1];
		t1 = t[1];
	}
	t[0] = t1;
	return (dist);
}

float   calc_cylinder_dist(t_cylinder *cylinder, float t, t_vec *vecs[2])
{
	float   dist;
	t_vec	*tmp[3];

	tmp[0] = ft_vec_dup(vecs[0]);
	ft_vec_mult(tmp[0], t);
	tmp[1] = ft_vec_substr(cylinder->center, vecs[1]);
	tmp[2] = ft_vec_substr(tmp[0], tmp[1]);
	dist = ft_vec_mult_dot(cylinder->direction, tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	return (dist);
	//  cylinder->direction * ((t * scene-vecs[0]) - (cylinder->center - scene->vecs[1]))
}

t_vec   *calc_cylinder_normal(float t[2], t_vec *vecs[2], t_cylinder *cylinder)
{
	float   dist;
	t_vec   *normal;
	t_vec   *tmp[2];

	dist = find_side_dist(t, cylinder);
	tmp[0] = ft_vec_dup(vecs[0]);
	ft_vec_mult(tmp[0], t[0]);
	tmp[1] = ft_vec_dup(cylinder->direction);
	ft_vec_mult(tmp[1], dist);
	normal = ft_vec_substr(tmp[0], tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	tmp[0] = normal;
	tmp[1] = ft_vec_substr(cylinder->center, vecs[1]);
	normal = ft_vec_substr(tmp[0], tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	ft_vec_norm(normal);
	return (normal);
}

float   check_cylinder_side(t_vec *vecs[2], t_vec **normal, t_cylinder *cylinder)
{
	float   t[2];

	if (cylinder_quadratic(t, cylinder, vecs) == 0)
		return (INFINITY);
	cylinder->dist[0] = calc_cylinder_dist(cylinder, t[0], vecs);
	cylinder->dist[1] = calc_cylinder_dist(cylinder, t[1], vecs);
	if (!((cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height && t[0] > 0.00001) || (cylinder->dist[1] >= 0 && cylinder->dist[1] <= cylinder->height && t[0] > 0.00001)))
		return (INFINITY);
	*normal = calc_cylinder_normal(t, vecs, cylinder);
	return (t[0]);
}

t_vec	*calc_cylinder_vec(t_vec *c, t_vec *d, float mult)
{
	t_vec	*center;
	t_vec	*tmp;

	center = ft_vec_dup(c);
	tmp = ft_vec_dup(d);
	ft_vec_mult(tmp, mult);
	ft_vec_add(center, tmp);
	free(tmp);
	return (center);
}

float	check_cylinder_caps(t_vec *vecs[2], t_cylinder *cylinder)
{
	t_vec	*center;
	t_vec	*dir[2];
	float	inter[2];
	float	min_inter;

	center = calc_cylinder_vec(cylinder->center, cylinder->direction, cylinder->height);
	inter[0] = plane_inter(vecs[1], vecs[0], cylinder->center, cylinder->direction);
	inter[1] = plane_inter(vecs[1], vecs[0], center, cylinder->direction);
	min_inter = inter[1];
	if (inter[0] < inter[1])
		min_inter = inter[0];
	if (inter[0] < INFINITY || inter[1] < INFINITY)
	{
		dir[0] = calc_cylinder_vec(vecs[1], vecs[0], inter[0]);
		dir[1] = calc_cylinder_vec(vecs[1], vecs[0], inter[1]);
		if ((inter[0] < INFINITY && ft_vec_dist(dir[0], cylinder->center) <= cylinder->radius)
			&& (inter[1] < INFINITY && ft_vec_dist(dir[1], cylinder->center) <= cylinder->radius))
			return (min_inter);
		else if (inter[0] < INFINITY && ft_vec_dist(dir[0], cylinder->center) <= cylinder->radius)
			return (inter[0]);
		else if (inter[1] < INFINITY && ft_vec_dist(dir[1], cylinder->center) <= cylinder->radius)
			return (inter[1]);
		return (INFINITY);
	}
	return (INFINITY);
}

float	cylinder_inter(t_vec *o, t_vec *d, t_figure *figure)
{
	float	side_inter;
	float	caps_inter;
	t_vec	*vecs[2];
	t_vec	*normal;

	vecs[0] = d;
	vecs[1] = o;
	normal = NULL;
	side_inter = check_cylinder_side(vecs, &normal, (t_cylinder *)figure->data);
	caps_inter = check_cylinder_caps(vecs, (t_cylinder *)figure->data);
	if (side_inter < INFINITY || caps_inter < INFINITY)
	{
		if (side_inter < caps_inter && side_inter > 0.001)
		{
			figure->normal = normal;
			return (side_inter);
		}
		figure->normal = ft_vec_dup(((t_cylinder *)figure->data)->direction);
		normal_check_and_reverse(figure->normal);
		return (caps_inter);
	}
	return (INFINITY);
}