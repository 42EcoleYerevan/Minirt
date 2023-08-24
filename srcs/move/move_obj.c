#include "geometry.h"
#include "minirt.h"

static void	ft_move_sphere(t_sphere *sphere, t_vec *vec);
static void	ft_move_plane(t_plane *plane, t_vec *vec);
static void	ft_move_cylinder(t_cylinder *cylinder, t_vec *vec);

void	ft_move_objects(t_scene *scene, t_vec *vec)
{
	t_figure	*figure;

	figure = scene->figure;
	while (figure)
	{
		if (figure->type == SPHERE)
			ft_move_sphere(figure->data, vec);
		else if (figure->type == PLANE)
			ft_move_plane(figure->data, vec);
		else if (figure->type == CYLINDER)
			ft_move_cylinder(figure->data, vec);
		figure = figure->next;
	}
}

static void	ft_move_sphere(t_sphere *sphere, t_vec *vec)
{
	ft_vec_add(sphere->center, vec);
}

static void	ft_move_plane(t_plane *plane, t_vec *vec)
{
	ft_vec_add(plane->point, vec);
}

static void	ft_move_cylinder(t_cylinder *cylinder, t_vec *vec)
{
	ft_vec_add(cylinder->center, vec);
}
