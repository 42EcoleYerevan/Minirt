#include "minirt.h"

void	ft_move_obj(t_scene *scene, t_vec vector)
{
	t_figure	*figure;

	figure = scene->figure;
	while (figure)
	{
		if (figure->type == 0)
			ft_move_sphere(figure, vector);
		else if (figure->type == 1)
			ft_move_plane(figure, vector);
		else if (figure->type == 2)
			ft_move_cylinder(figure, vector);
		figure = figure->next;
	}
}

void	ft_move_sphere(t_figure *figure, t_vec vector)
{
	t_sphere	*sphere;

	sphere = figure->data;
	sphere->center = ft_vec_add(sphere->center, vector);
}

void	ft_move_plane(t_figure *figure, t_vec vector)
{
	t_plane	*plane;

	plane = figure->data;
	plane->point = ft_vec_add(plane->point, vector);
}

void	ft_move_cylinder(t_figure *figure, t_vec vector)
{
	t_cylinder	*cylinder;

	cylinder = figure->data;
	cylinder->center = ft_vec_add(cylinder->center, vector);
}
