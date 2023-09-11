/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:14 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:41:29 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_camera(t_scene *scene)
{
	t_camera	*camera;

	camera = scene->cams;
	printf("Camera:\n");
	printf("Origin: %f %f %f\n", camera->origin.x, \
			camera->origin.y, camera->origin.z);
	printf("Direction: %f %f %f\n", camera->direction.x, \
			camera->direction.y, camera->direction.z);
	printf("FOV: %f\n\n", camera->fov);
}

void	ft_print_light(t_scene *scene)
{
	t_light	*light;

	light = scene->light;
	while (light)
	{
		printf("Light:\n");
		printf("Center: %f %f %f\n", light->center.x, \
				light->center.y, light->center.z);
		printf("Brightness: %f\n", light->brightness);
		printf("Color: %d %d %d\n\n", light->color->r, \
				light->color->g, light->color->b);
		light = light->next;
	}
}

void	ft_print_sphere(t_figure *figure)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)figure->data;
	printf("Sphere:\n");
	printf("Center: %f %f %f\n", sphere->center.x, \
			sphere->center.y, sphere->center.z);
	printf("Radius: %f\n", sphere->radius);
	printf("Color: %d %d %d\n\n", figure->color->r, \
			figure->color->g, figure->color->b);
}

void	ft_print_plane(t_figure *figure)
{
	t_plane	*plane;

	plane = (t_plane *)figure->data;
	printf("Plane:\n");
	printf("Point: %f %f %f\n", plane->point.x, \
			plane->point.y, plane->point.z);
	printf("Normal: %f %f %f\n", plane->normal.x, \
			plane->normal.y, plane->normal.z);
	printf("Color: %d %d %d\n\n", figure->color->r, \
			figure->color->g, figure->color->b);
}

void	ft_print_cylinder(t_figure *figure)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)figure->data;
	printf("Cylinder:\n");
	printf("Center: %f %f %f\n", cylinder->center.x, \
			cylinder->center.y, cylinder->center.z);
	printf("Direction: %f %f %f\n", cylinder->direction.x, \
			cylinder->direction.y, cylinder->direction.z);
	printf("Radius: %f\n", cylinder->radius);
	printf("Height: %f\n", cylinder->height);
	printf("Color: %d %d %d\n\n", figure->color->r, \
			figure->color->g, figure->color->b);
}
