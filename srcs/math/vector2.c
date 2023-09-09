/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:10:17 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/09 19:54:41 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_vec_substr(t_vec vec1, t_vec vec2)
{
	t_vec	res;

	res = vec1;
	res.x -= vec2.x;
	res.y -= vec2.y;
	res.z -= vec2.z;
	return (res);
}

float	ft_vec_mult_dot(t_vec vec1, t_vec vec2)
{
	float	res;

	res = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (res);
}

t_vec	ft_vec_norm(t_vec vec)
{
	float	len;

	len = ft_vec_len(vec);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

t_vec	ft_vec_cross(t_vec vec1, t_vec vec2)
{
	t_vec	res;

	res.x = vec1.y * vec2.z - vec1.z * vec2.y;
	res.y = vec1.z * vec2.x - vec1.x * vec2.z;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (res);
}

float	ft_vec_dist(t_vec v1, t_vec v2)
{
	float	dist;

	dist = sqrt(pow(v2.x - v1.x, 2)
			+ pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (dist);
}
