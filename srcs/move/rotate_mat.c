/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:33:12 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 13:33:13 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_xrotate_matrix(float angle)
{
	t_matrix	m;

	m = ft_identity_matrix();
	m.m[5] = cos(angle);
	m.m[6] = -sin(angle);
	m.m[9] = sin(angle);
	m.m[10] = cos(angle);
	return (m);
}

t_matrix	ft_yrotate_matrix(float angle)
{
	t_matrix	m;

	m = ft_identity_matrix();
	m.m[0] = cos(angle);
	m.m[2] = sin(angle);
	m.m[8] = -sin(angle);
	m.m[10] = cos(angle);
	return (m);
}

t_matrix	ft_zrotate_matrix(float angle)
{
	t_matrix	m;

	m = ft_identity_matrix();
	m.m[0] = cos(angle);
	m.m[1] = -sin(angle);
	m.m[4] = sin(angle);
	m.m[5] = cos(angle);
	return (m);
}
