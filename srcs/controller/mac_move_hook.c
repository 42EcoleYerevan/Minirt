#include "minirt.h"

void	ft_mac_figure_move_hook(t_scene *scene, int keycode)
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
	ft_move_object(scene->current_figure, vec);
}

void	ft_mac_rotate_figure_hook(t_scene *scene, int keycode)
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
	ft_rotate_object(scene, matrix);
}
