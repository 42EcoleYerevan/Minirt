#include "minirt.h"

static void	ft_move_sphere(t_sphere *sphere, float *view_matrix);
static void	ft_move_plane(t_plane *plane, float *view_matrix);
static void	ft_move_cylinder(t_cylinder *cylinder, float *view_matrix);

void ft_move_scene_to_camera(t_scene *scene, t_camera *camera)
{
	t_figure	*figure;
	float		*view_matrix;

	figure = scene->figure;
	view_matrix = ft_view_matrix(camera);
	while (figure)
	{
		if (figure->type == SPHERE)
			ft_move_sphere(figure->data, view_matrix);
		else if (figure->type == PLANE)
			ft_move_plane(figure->data, view_matrix);
		else if (figure->type == CYLINDER)
			ft_move_cylinder(figure->data, view_matrix);
		figure = figure->next;
	}
}

static void	ft_move_sphere(t_sphere *sphere, float *view_matrix)
{
	ft_vec_mult_mat(sphere->center, view_matrix);
}

static void	ft_move_plane(t_plane *plane, float *view_matrix)
{
	ft_vec_mult_mat(plane->center, view_matrix);
}

static void	ft_move_cylinder(t_cylinder *cylinder, float *view_matrix)
{
	ft_vec_mult_mat(cylinder->center, view_matrix);
}
