/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:05 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 17:32:39 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*ft_copy_sphere(t_figure *figure);
t_figure	*ft_copy_plane(t_figure *figure);
t_figure	*ft_copy_cylinder(t_figure *figure);

void	ft_add_current_figure(t_scene *scene)
{
	t_figure	*tmp;

	if (scene->current_figure == NULL)
		return ;
	if (scene->current_figure->type == SPHERE)
		tmp = ft_copy_sphere(scene->current_figure);
	else if (scene->current_figure->type == PLANE)
		tmp = ft_copy_plane(scene->current_figure);
	else if (scene->current_figure->type == CYLINDER)
		tmp = ft_copy_cylinder(scene->current_figure);
	else
		return ;
	ft_add_figure(scene, tmp);
	scene->current_figure = tmp;
}

t_figure	*ft_copy_sphere(t_figure *figure)
{
	t_sphere	*sphere;
	t_figure	*copy;

	sphere = figure->data;
	copy = new_sphere(sphere->center, sphere->radius, figure->color);
	copy->normal = figure->normal;
	return (copy);
}

t_figure	*ft_copy_plane(t_figure *figure)
{
	t_plane		*plane;
	t_figure	*copy;

	plane = figure->data;
	copy = new_plane(plane->point, plane->normal, figure->color);
	copy->normal = figure->normal;
	return (copy);
}

t_figure	*ft_copy_cylinder(t_figure *figure)
{
	t_cylinder	*cylinder;
	t_figure	*copy;
	float		radius_height[2];

	cylinder = figure->data;
	radius_height[0] = cylinder->radius;
	radius_height[1] = cylinder->height;
	copy = new_cylinder(cylinder->center, cylinder->direction, \
				radius_height, figure->color);
	copy->normal = figure->normal;
	return (copy);
}
