/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:48 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:42:09 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_light(t_scene *scene);
void	ft_print_camera(t_scene *scene);
void	ft_print_ambient(t_ambient *ambient);
void	ft_print_matrix(float *matrix);

void	ft_print_scene(t_scene *scene)
{
	t_figure	*figure;

	ft_print_ambient(scene->ambient);
	ft_print_camera(scene);
	ft_print_light(scene);
	figure = scene->figure;
	while (figure)
	{
		if (figure->type == SPHERE)
			ft_print_sphere(figure);
		else if (figure->type == PLANE)
			ft_print_plane(figure);
		else if (figure->type == CYLINDER)
			ft_print_cylinder(figure);
		figure = figure->next;
	}
}

void	ft_print_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("Brightness: %f\n", ambient->brightness);
	printf("Color: %d %d %d\n\n", ambient->color->r, \
			ambient->color->g, ambient->color->b);
}

void	ft_print_vec(t_vec vec)
{
	printf("x: %f, y: %f, z: %f\n", vec.x, vec.y, vec.z);
}

void	ft_print_matrix(float *matrix)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("%f ", matrix[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
		i++;
	}
}
