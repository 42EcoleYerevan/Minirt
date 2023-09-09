/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:34:59 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/05 18:16:20 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*new_sphere(t_vec vec, float radius, t_color *color)
{
	t_figure	*figure;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		err_exit("err: memory allocating failed.\n");
	sphere->center = vec;
	sphere->radius = radius;
	figure = new_figure(sphere, SPHERE);
	figure->color = color;
	figure->specular = 100;
	figure->next = NULL;
	return (figure);
}
