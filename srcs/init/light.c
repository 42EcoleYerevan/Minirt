/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:34:59 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/05 18:13:48 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*new_light(t_vec center, float brightness, t_color *color)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		err_exit("err: memory allocating failed.\n");
	new->color = color;
	new->center = center;
	new->brightness = brightness;
	new->next = NULL;
	return (new);
}
