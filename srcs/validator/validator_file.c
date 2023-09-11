/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:47:07 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 18:01:18 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_empty_file(char **lines)
{
	if (!lines)
		err_exit("Empty file");
	if (!lines[0])
		err_exit("Empty file");
	return (0);
}
