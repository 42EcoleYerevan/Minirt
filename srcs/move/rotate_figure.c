/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:33:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:33:21 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_rotate_object(t_scene *scene, t_matrix matrix)
{
	if (scene->current_figure->type == PLANE)
		ft_rotate_plane_norm(scene->current_figure->data, matrix);
	else if (scene->current_figure->type == CYLINDER)
		ft_rotate_cylinder_norm(scene->current_figure->data, matrix);
}

void	ft_rotate_plane_norm(t_plane *plane, t_matrix matrix)
{
	plane->normal = ft_vec_mult_mat(plane->normal, matrix);
}

void	ft_rotate_cylinder_norm(t_cylinder *cylinder, t_matrix matrix)
{
	cylinder->direction = ft_vec_mult_mat(cylinder->direction, matrix);
}
