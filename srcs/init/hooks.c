/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:06:38 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/10 17:32:16 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int ft_close(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	exit(0);
	return (0);
}

void	ft_init_hooks(t_scene *scene)
{
	mlx_hook(scene->win, 4, 0, ft_mousedown_hook, scene);
	mlx_hook(scene->win, 5, 0, ft_mouseup_hook, scene);
	mlx_hook(scene->win, 6, 0, ft_mousemove_hook, scene);
	mlx_hook(scene->win, 17, 0, ft_close, scene);
	mlx_key_hook(scene->win, key_hook, scene);
}
