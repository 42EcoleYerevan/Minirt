/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:34:59 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/05 18:23:47 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_vec_len(t_vec vec)
{
	float	len;

	len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (len);
}

t_vec	ft_vec_add(t_vec vec1, t_vec vec2)
{
	t_vec	res;

	res = vec1;
	res.x += vec2.x;
	res.y += vec2.y;
	res.z += vec2.z;
	res.w += vec2.w;
	return (res);
}

t_vec	ft_vec_mult(t_vec vec, float mult)
{
	t_vec	res;

	res = vec;
	res.x *= mult;
	res.y *= mult;
	res.z *= mult;
	res.w *= mult;
	return (res);
}
