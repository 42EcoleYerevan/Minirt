#include "minirt.h"

static void	ft_rotate_cylinder(t_figure *figure, float *matrix);
static void	ft_rotate_plane(t_figure *figure, float *matrix);
static void	ft_rotate_sphere(t_sphere *sphere, float *matrix);

void ft_rotate_objects(t_scene *scene, float *matrix)
{
	t_figure	*figure;

	figure = scene->figure;
	while (figure)
	{
		if (figure->type == SPHERE)
			ft_rotate_sphere(figure->data, matrix);
		else if (figure->type == PLANE)
			ft_rotate_plane(figure, matrix);
		else if (figure->type == CYLINDER)
			ft_rotate_cylinder(figure, matrix);
		figure = figure->next;
	}
}

static void	ft_rotate_sphere(t_sphere *sphere, float *matrix)
{
	ft_vec_mult_mat(sphere->center, matrix);
}

static void	ft_rotate_plane(t_figure *figure, float *matrix)
{
	t_plane		*plane;

	plane = figure->data;
	ft_vec_mult_mat(plane->point, matrix);
	ft_vec_mult_mat(plane->normal, matrix);
	ft_vec_mult_mat(figure->normal, matrix);
}

static void	ft_rotate_cylinder(t_figure *figure, float *matrix)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)figure->data;
	ft_vec_mult_mat(cylinder->center, matrix);
	ft_vec_mult_mat(cylinder->direction, matrix);
	ft_vec_mult_mat(figure->normal, matrix);
}
