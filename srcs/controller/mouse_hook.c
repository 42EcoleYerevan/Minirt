/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:36:13 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mouse_scroll_hook(int keycode, t_scene *scene)
{
	if (keycode == 4)
		ft_zmove_scene(scene, scene->zmove);
	else if (keycode == 5)
		ft_zmove_scene(scene, -scene->zmove);
}

int	ft_mousedown_hook(int keycode, int x, int y, t_scene *scene)
{
	t_vec	d;
	float	x_angle;
	float	y_angle;

	scene->current_figure = NULL;
	scene->button = keycode;
	if (keycode == 1)
	{
		y_angle = (scene->height / 2 + 1) - y;
		x_angle = ((scene->width / 2) * (-1) - 1) + x;
		d = ft_vec_norm(new_4vector(x_angle * scene->vplane->x_pixel, \
				y_angle * scene->vplane->y_pixel, -1, 1));
		closest_inter(scene->figure, &scene->current_figure, \
				scene->cams->origin, d);
		if (!scene->current_figure)
			return (0);
	}
	ft_mouse_scroll_hook(keycode, scene);
	render(scene);
	return (0);
}

int	ft_mouseup_hook(int keycode, int x, int y, t_scene *scene)
{
	(void)keycode;
	(void)x;
	(void)y;
	scene->button = -1;
	render(scene);
	return (0);
}

int	ft_mousemove_hook(int x, int y, t_scene *scene)
{
	static int	old_x = 0;
	static int	old_y = 0;

	if (scene->button == 1 && old_x != 0 && old_y != 0)
	{
		ft_xrotate_scene(scene, (y - old_y) * -0.01);
		ft_yrotate_scene(scene, (x - old_x) * -0.01);
		scene->current_figure = NULL;
	}
	old_x = x;
	old_y = y;
	render(scene);
	return (0);
}
