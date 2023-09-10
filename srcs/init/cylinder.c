/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:15:54 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/09 19:49:42 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*new_cylinder(t_vec center, t_vec direction,
	float radius_height[2], t_color *color)
{
	t_figure	*figure;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		err_exit("err: memory allocating failed.\n");
	cylinder->center = center;
	cylinder->direction = direction;
	cylinder->radius = radius_height[0];
	cylinder->height = radius_height[1];
	figure = new_figure(cylinder, CYLINDER);
	figure->color = color;
	figure->specular = 100;
	figure->normal = cylinder->direction;
	figure->next = NULL;
	return (figure);
}
