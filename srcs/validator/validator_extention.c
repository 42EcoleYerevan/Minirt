/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_extention.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:01:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:01:48 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_valid_extension(char *filename)
{
	filename += ft_strlen(filename) - 3;
	if (ft_strncmp(filename, ".rt", 3) == 0)
		return (0);
	return (1);
}
