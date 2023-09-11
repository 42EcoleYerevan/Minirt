/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:01:55 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:01:55 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_valid_cylinder(char **tokens)
{
	if (ft_arrlen(tokens) != 6)
		return (1);
	if (ft_is_valid_vector(tokens[1]))
		return (1);
	if (ft_is_valid_direction(tokens[2]))
		return (1);
	if (ft_is_valid_float(tokens[3]))
		return (1);
	if (ft_is_valid_float(tokens[4]))
		return (1);
	if (ft_is_valid_color(tokens[5]))
		return (1);
	return (0);
}
