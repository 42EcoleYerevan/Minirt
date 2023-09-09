/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:17:51 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/09 16:17:51 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	calc_cylinder_normal(float t[2], t_vec vecs[2], t_cylinder *cylinder)
{
	float	dist;

	dist = choose_cylinder_dist(t, cylinder);
	return (ft_vec_norm(ft_vec_substr(ft_vec_substr(ft_vec_mult(vecs[0], t[0]),
					ft_vec_mult(cylinder->direction, dist)),
				ft_vec_substr(cylinder->center, vecs[1]))));
}

float	calc_cylinder_dist(t_cylinder *cylinder, t_vec vecs[2], float t)
{
	float	dist;

	dist = ft_vec_mult_dot(cylinder->direction,
			ft_vec_substr(ft_vec_mult(vecs[0], t),
				ft_vec_substr(cylinder->center, vecs[1])));
	return (dist);
}

float	calc_side_inter(t_vec vecs[2], t_vec *normal, t_cylinder *cylinder)
{
	float	t[2];

	if (quadratic_cylinder(t, vecs, cylinder) == 0)
		return (INFINITY);
	cylinder->dist[0] = calc_cylinder_dist(cylinder, vecs, t[0]);
	cylinder->dist[1] = calc_cylinder_dist(cylinder, vecs, t[1]);
	if (!((cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height
				&& t[0] > EPSILON)
			|| (cylinder->dist[1] >= 0 && cylinder->dist[1] <= cylinder->height
				&& t[0] > EPSILON)))
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
	if (inter[0] < INFINITY || inter[1] < INFINITY)
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

float	cylinder_inter(t_vec o, t_vec d, t_figure *figure)
{
	float	side_inter;
	float	caps_inter;
	t_vec	vecs[2];
	t_vec	normal;

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
			return (caps_inter);
		}
	}
	return (INFINITY);
}
