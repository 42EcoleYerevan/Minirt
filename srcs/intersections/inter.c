/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:30:07 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:30:08 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	closest_inter(t_figure *figure, t_figure **obj, t_vec o, t_vec d)
{
	float	min_t;
	float	t;

	t = INFINITY;
	min_t = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			t = sphere_inter(o, d, (t_sphere *)figure->data);
		else if (figure->type == CYLINDER)
			t = cylinder_inter(o, d, figure);
		else
			t = plane_inter(o, d, (((t_plane *)figure->data)->point),
					(((t_plane *)figure->data)->normal));
		if ((t > EPSILON) && (t < min_t))
		{
			min_t = t;
			*obj = figure;
		}
		figure = figure->next;
	}
	return (min_t);
}
