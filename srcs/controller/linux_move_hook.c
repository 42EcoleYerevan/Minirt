#include "minirt.h"

void	ft_linux_obj_move(t_scene *scene, int keycode)
{
	t_vec vec;

	if (keycode == 65362)
		vec = new_vector(0, 0, -scene->zmove);
	else if (keycode == 65361)
		vec = new_vector(-scene->xmove, 0, 0);
	else if (keycode == 65364)
		vec = new_vector(0, 0, scene->zmove);
	else if (keycode == 65363)
		vec = new_vector(scene->xmove, 0, 0);
	else if (keycode == 122)
		vec = new_vector(0, -scene->ymove, 0);
	else if (keycode == 120)
		vec = new_vector(0, scene->ymove, 0);
	else
		return ;
	ft_move_object(scene->current_figure, vec);
}

void	ft_linux_rotate_figure_hook(t_scene *scene, int keycode)
{
	t_matrix matrix;

	if (keycode == 97)
		matrix = ft_xrotate_matrix(scene->x_angle);
	else if (keycode == 115)
		matrix = ft_yrotate_matrix(scene->y_angle);
	else if (keycode == 100)
		matrix = ft_zrotate_matrix(scene->z_angle);
	else if (keycode == 113)
		matrix = ft_xrotate_matrix(-scene->x_angle);
	else if (keycode == 119)
		matrix = ft_yrotate_matrix(-scene->y_angle);
	else if (keycode == 101)
		matrix = ft_zrotate_matrix(-scene->z_angle);
	else
		return ;
	ft_rotate_object(scene, matrix);
}
