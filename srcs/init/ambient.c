/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:34:59 by almeliky          #+#    #+#             */
/*   Updated: 2023/08/25 15:34:59 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	*new_ambient(t_color *color, float brightness)
{
	t_ambient	*ambient;

	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->color = color;
	ambient->brightness = brightness;
	return (ambient);
}
