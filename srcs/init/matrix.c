/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:06:38 by almeliky          #+#    #+#             */
/*   Updated: 2023/09/09 15:06:38 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_new_zero_matrix(void)
{
	int			row;
	int			col;
	t_matrix	mat;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat.m[row * 4 + col] = 0;
			col++;
		}
		row++;
	}
	return (mat);
}

t_matrix	ft_identity_matrix(void)
{
	int			row;
	int			col;
	t_matrix	mat;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat.m[row * 4 + col] = (row == col);
			col++;
		}
		row++;
	}
	return (mat);
}
