/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:47:04 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/10 16:39:46 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	quadratic_vecs(t_vec *pv1, t_vec *pv2, t_cylinder *cy, t_vec vecs[2])
{
	t_vec	v1;
	t_vec	v2;

	v1 = ft_vec_mult(cy->direction, ft_vec_mult_dot(vecs[0], cy->direction));
	v1 = ft_vec_substr(vecs[0], v1);
	v2 = ft_vec_mult(cy->direction,
			ft_vec_mult_dot(ft_vec_substr(vecs[1], cy->center), cy->direction));
	v2 = ft_vec_substr(ft_vec_substr(vecs[1], cy->center), v2);
	*pv1 = v1;
	*pv2 = v2;
}

int	quadratic_cylinder(float t[2], t_vec vecs[2], t_cylinder *cy)
{
	t_vec	v1;
	t_vec	v2;
	t_abc	abc;

	quadratic_vecs(&v1, &v2, cy, vecs);
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
	float	t1;

	if ((cy->dist[0] >= 0 && cy->dist[0] <= cy->height && t[0] > EPSILON)
		&& (cy->dist[1] >= 0 && cy->dist[1] <= cy->height && t[1] > EPSILON))
	{
		dist = cy->dist[1];
		t1 = t[1];
		if (t[0] < t[1])
			dist = cy->dist[0];
		if (t[0] < t[1])
			t1 = t[0];
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
