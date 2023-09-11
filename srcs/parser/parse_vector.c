/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:30:57 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:30:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_parse_vector(char *str)
{
	t_vec	vector;
	char	**tokens;

	tokens = ft_split(str, ',');
	vector = new_vector(ft_atof(tokens[0]), \
						ft_atof(tokens[1]), \
						ft_atof(tokens[2]));
	ft_free_arr(tokens);
	return (vector);
}
