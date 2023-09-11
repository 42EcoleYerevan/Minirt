/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:34:04 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:34:05 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_move_object(t_figure *figure, t_vec vec)
{
	if (figure->type == SPHERE)
		ft_move_sphere(figure, vec);
	else if (figure->type == PLANE)
		ft_move_plane(figure, vec);
	else if (figure->type == CYLINDER)
		ft_move_cylinder(figure, vec);
}
