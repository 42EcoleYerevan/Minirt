/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:43:05 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 16:57:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_save_sphere(t_figure *figure, int fd);
void	ft_save_plane(t_figure *figure, int fd);
void	ft_save_cylinder(t_figure *figure, int fd);

void	ft_save_figures(t_figure *figure, int fd)
{
	while (figure)
	{
		if (figure->type == 0)
			ft_save_sphere(figure, fd);
		else if (figure->type == 1)
			ft_save_plane(figure, fd);
		else if (figure->type == 2)
			ft_save_cylinder(figure, fd);
		figure = figure->next;
	}
}

void	ft_save_sphere(t_figure *figure, int fd)
{
	t_sphere	*sphere;

	sphere = figure->data;
	write(fd, "sp ", 3);
	ft_write_vector(sphere->center, fd);
	write(fd, " ", 1);
	write(fd, ft_ftoa(sphere->radius * 2), \
			ft_strlen(ft_ftoa(sphere->radius * 2)));
	write(fd, " ", 1);
	ft_write_color(figure->color, fd);
	write(fd, "\n", 1);
}

void	ft_save_plane(t_figure *figure, int fd)
{
	t_plane	*plane;

	plane = figure->data;
	write(fd, "pl ", 3);
	ft_write_vector(plane->point, fd);
	write(fd, " ", 1);
	ft_write_vector(plane->normal, fd);
	write(fd, " ", 1);
	ft_write_color(figure->color, fd);
	write(fd, "\n", 1);
}

void	ft_save_cylinder(t_figure *figure, int fd)
{
	t_cylinder	*cylinder;

	cylinder = figure->data;
	write(fd, "cy ", 3);
	ft_write_vector(cylinder->center, fd);
	write(fd, " ", 1);
	ft_write_vector(cylinder->direction, fd);
	write(fd, " ", 1);
	write(fd, ft_itoa(cylinder->radius), \
			ft_strlen(ft_itoa(cylinder->radius)));
	write(fd, " ", 1);
	write(fd, ft_itoa(cylinder->height), \
			ft_strlen(ft_itoa(cylinder->height)));
	write(fd, " ", 1);
	ft_write_color(figure->color, fd);
	write(fd, "\n", 1);
}
