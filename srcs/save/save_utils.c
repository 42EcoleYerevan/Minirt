/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:32:18 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 17:32:19 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_write_color(t_color *color, int fd)
{
	write(fd, ft_itoa(color->r), ft_strlen(ft_itoa(color->r)));
	write(fd, ",", 1);
	write(fd, ft_itoa(color->g), ft_strlen(ft_itoa(color->g)));
	write(fd, ",", 1);
	write(fd, ft_itoa(color->b), ft_strlen(ft_itoa(color->b)));
}

void	ft_write_vector(t_vec vec, int fd)
{
	write(fd, ft_ftoa(vec.x), ft_strlen(ft_ftoa(vec.x)));
	write(fd, ",", 1);
	write(fd, ft_ftoa(vec.y), ft_strlen(ft_ftoa(vec.y)));
	write(fd, ",", 1);
	write(fd, ft_ftoa(vec.z), ft_strlen(ft_ftoa(vec.z)));
}

void	ft_write_float(float n, int fd)
{
	write(fd, ft_ftoa(n), ft_strlen(ft_ftoa(n)));
}
