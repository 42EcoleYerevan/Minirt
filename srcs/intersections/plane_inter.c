/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:22:04 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/09 15:22:04 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	plane_inter(t_vec o, t_vec d, t_vec point, t_vec normal)
{
	float	denom;
	float	x;

	denom = ft_vec_mult_dot(normal, d);
	if (denom == 0)
		return (INFINITY);
	x = ft_vec_mult_dot(ft_vec_substr(point, o), normal) / denom;
	if (x >= EPSILON)
		return (x);
	return (INFINITY);
}
