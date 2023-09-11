/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:01:16 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:01:17 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_valid_plane(char **tokens)
{
	if (ft_arrlen(tokens) != 4)
		return (1);
	if (ft_is_valid_vector(tokens[1]))
		return (1);
	if (ft_is_valid_direction(tokens[2]))
		return (1);
	if (ft_is_valid_color(tokens[3]))
		return (1);
	return (0);
}
