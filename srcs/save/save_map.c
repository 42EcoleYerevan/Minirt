/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:53:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/09/11 16:56:29 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_save_ambient(t_ambient *ambient, int fd);
void	ft_save_cameras(t_camera *cams, int fd);
void	ft_save_lights(t_light *light, int fd);
void	ft_save_figures(t_figure *figure, int fd);
char	*ft_rgb_to_str(t_color *color);
char	*ft_itohex(int n);

void	ft_save_map(t_scene *scene)
{
	int	fd;

	fd = open("scenes/new_map.rt", O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		err_exit("Error\n\tCan't create file");
	ft_save_ambient(scene->ambient, fd);
	ft_save_cameras(scene->cams, fd);
	ft_save_lights(scene->light, fd);
	ft_save_figures(scene->figure, fd);
}

void	ft_save_ambient(t_ambient *ambient, int fd)
{
	write(fd, "A ", 2);
	write(fd, ft_ftoa(ambient->brightness), \
			ft_strlen(ft_ftoa(ambient->brightness)));
	write(fd, " ", 1);
	ft_write_color(ambient->color, fd);
	write(fd, "\n", 1);
}

void	ft_save_cameras(t_camera *cams, int fd)
{
	write(fd, "C ", 2);
	ft_write_vector(cams->origin, fd);
	write(fd, " ", 1);
	ft_write_vector(cams->direction, fd);
	write(fd, " ", 1);
	write(fd, ft_itoa(cams->fov), ft_strlen(ft_itoa(cams->fov)));
	write(fd, "\n", 1);
}

void	ft_save_lights(t_light *light, int fd)
{
	while (light)
	{
		write(fd, "L ", 2);
		ft_write_vector(light->center, fd);
		write(fd, " ", 1);
		write(fd, ft_ftoa(light->brightness), \
				ft_strlen(ft_ftoa(light->brightness)));
		write(fd, " ", 1);
		ft_write_color(light->color, fd);
		write(fd, "\n", 1);
		light = light->next;
	}
}
