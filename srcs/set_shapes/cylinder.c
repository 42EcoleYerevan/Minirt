/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:25:24 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:25:25 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_set_cylinder(char **tokens, t_scene *scene)
{
	t_figure	*figure;
	float		radius_height[2];

	radius_height[0] = ft_atof(tokens[3]);
	radius_height[1] = ft_atof(tokens[4]);
	figure = new_cylinder(ft_get_vector_from_token(tokens[1]), \
							ft_get_vector_from_token(tokens[2]), \
							radius_height, \
							ft_get_color_from_token(tokens[5]));
	if (!figure)
		return (1);
	ft_add_figure(scene, figure);
	return (0);
}
