#include "geometry.h"
#include "minirt.h"

void	ft_mac_move_object(t_figure *figure, t_vec vec);
void	ft_mac_figure_move(t_scene *scene, int keycode);
void	ft_mac_rotate_object(t_scene *scene, t_matrix matrix);
void	ft_mac_rotate_figure(t_scene *scene, int keycode);
void	ft_rotate_plane_norm(t_plane *plane, t_matrix matrix);
void	ft_rotate_cylinder_norm(t_cylinder *cylinder, t_matrix matrix);

void ft_mac_hooks(int keycode, t_scene *scene)
{
	ft_ui_keyhook(keycode, scene);
	if (scene->current_figure)
	{
		ft_mac_figure_move(scene, keycode);
		ft_mac_rotate_figure(scene, keycode);
		return ;
	}
	ft_rotate_keyhook(keycode, scene);
	ft_move_keyhook(keycode, scene);
}

void ft_rotate_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 13)
		ft_xrotate_scene(scene, scene->x_angle);
	else if (keycode == 0)
		ft_yrotate_scene(scene, scene->y_angle);
	else if (keycode == 1)
		ft_xrotate_scene(scene, -scene->x_angle);
	else if (keycode == 2)
		ft_yrotate_scene(scene, -scene->y_angle);
	else if (keycode == 12)
		ft_zrotate_scene(scene, scene->z_angle);
	else if (keycode == 14)
		ft_zrotate_scene(scene, -scene->z_angle);
}

void	ft_move_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 126)
		ft_zmove_scene(scene, scene->zmove);
	else if (keycode == 123)
		ft_xmove_scene(scene, scene->xmove);
	else if (keycode == 125)
		ft_zmove_scene(scene, -scene->zmove);
	else if (keycode == 124)
		ft_xmove_scene(scene, -scene->xmove);
	else if (keycode == 6)
		ft_ymove_scene(scene, -scene->ymove);
	else if (keycode == 7)
		ft_ymove_scene(scene, scene->ymove);
}

void	ft_ui_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 32)
		scene->ui = -scene->ui;
	else if (keycode == 53)
		exit(0);
}

void	ft_mac_rotate_figure(t_scene *scene, int keycode)
{
	t_matrix matrix;

	if (keycode == 13)
		matrix = ft_xrotate_matrix(scene->x_angle);
	else if (keycode == 0)
		matrix = ft_yrotate_matrix(scene->y_angle);
	else if (keycode == 1)
		matrix = ft_xrotate_matrix(-scene->x_angle);
	else if (keycode == 2)
		matrix = ft_yrotate_matrix(-scene->y_angle);
	else if (keycode == 12)
		matrix = ft_zrotate_matrix(scene->z_angle);
	else if (keycode == 14)
		matrix = ft_zrotate_matrix(-scene->z_angle);
	else
		return ;
	ft_mac_rotate_object(scene, matrix);
}

void	ft_mac_rotate_object(t_scene *scene, t_matrix matrix)
{
	if (scene->current_figure->type == PLANE)
		ft_rotate_plane_norm(scene->current_figure->data, matrix);
	else if (scene->current_figure->type == CYLINDER)
		ft_rotate_cylinder_norm(scene->current_figure->data, matrix);
}

void	ft_rotate_plane_norm(t_plane *plane, t_matrix matrix)
{
	plane->normal = ft_vec_mult_mat(plane->normal, matrix);
}

void	ft_rotate_cylinder_norm(t_cylinder *cylinder, t_matrix matrix)
{
	cylinder->direction = ft_vec_mult_mat(cylinder->direction, matrix);
}

void	ft_mac_figure_move(t_scene *scene, int keycode)
{
	t_vec vec;

	if (keycode == 126)
		vec = new_vector(0, 0, -scene->zmove);
	else if (keycode == 123)
		vec = new_vector(-scene->xmove, 0, 0);
	else if (keycode == 125)
		vec = new_vector(0, 0, scene->zmove);
	else if (keycode == 124)
		vec = new_vector(scene->xmove, 0, 0);
	else if (keycode == 6)
		vec = new_vector(0, -scene->ymove, 0);
	else if (keycode == 7)
		vec = new_vector(0, scene->ymove, 0);
	else
		return ;
	ft_mac_move_object(scene->current_figure, vec);
}

void	ft_mac_move_object(t_figure *figure, t_vec vec)
{
	if (figure->type == SPHERE)
		ft_move_sphere(figure, vec);
	else if (figure->type == PLANE)
		ft_move_plane(figure, vec);
	else if (figure->type == CYLINDER)
		ft_move_cylinder(figure, vec);
}
