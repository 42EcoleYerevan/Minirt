/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:33:52 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:33:53 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_move_light(t_light *light, t_vec vector);

void	ft_xmove_scene(t_scene *scene, float step)
{
	t_vec	vector;

	vector = new_4vector(step, 0, 0, 0);
	ft_move_obj(scene, vector);
	ft_move_light(scene->light, vector);
}

void	ft_ymove_scene(t_scene *scene, float step)
{
	t_vec	vector;

	vector = new_4vector(0, step, 0, 0);
	ft_move_obj(scene, vector);
	ft_move_light(scene->light, vector);
}

void	ft_zmove_scene(t_scene *scene, float step)
{
	t_vec	vector;

	vector = new_4vector(0, 0, step, 0);
	ft_move_obj(scene, vector);
	ft_move_light(scene->light, vector);
}

static void	ft_move_light(t_light *light, t_vec vector)
{
	while (light)
	{
		light->center = ft_vec_add(light->center, vector);
		light = light->next;
	}
}
