/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:18:22 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:18:23 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_valid_ambient(char **tokens)
{
	float	ratio;

	if (ft_arrlen(tokens) != 3)
		return (1);
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (1);
	if (ft_is_valid_color(tokens[2]))
		return (1);
	return (0);
}
