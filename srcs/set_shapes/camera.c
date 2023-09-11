/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:25:45 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:25:46 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_set_camera(char **tokens, t_scene *scene)
{
	t_camera	*camera;
	t_vec		center;
	t_vec		direction;
	float		fov;

	if (!tokens || !scene)
		return (1);
	center = ft_get_vector_from_token(tokens[1]);
	direction = ft_get_vector_from_token(tokens[2]);
	fov = ft_atof(tokens[3]);
	camera = new_camera(center, direction, fov);
	if (!camera)
		return (1);
	scene->cams = camera;
	return (0);
}
