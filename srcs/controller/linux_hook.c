#include "geometry.h"
#include "minirt.h"

void	ft_move_figure(t_figure *figure, t_vec vec);
void	ft_linux_obj_move(t_scene *scene, int keycode);

void ft_linux_hooks(int keycode, t_scene *scene)
{
	if (scene->current_figure)
	{
		ft_linux_obj_move(scene, keycode);
		return ;
	}
	ft_linux_rotate_keyhook(keycode, scene);
	ft_linux_move_keyhook(keycode, scene);
	ft_linux_ui_keyhook(keycode, scene);
}

void ft_linux_rotate_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 119)
		ft_xrotate_scene(scene, scene->x_angle);
	else if (keycode == 97)
		ft_yrotate_scene(scene, scene->y_angle);
	else if (keycode == 115)
		ft_xrotate_scene(scene, -scene->x_angle);
	else if (keycode == 100)
		ft_yrotate_scene(scene, -scene->y_angle);
	else if (keycode == 113)
		ft_zrotate_scene(scene, scene->z_angle);
	else if (keycode == 101)
		ft_zrotate_scene(scene, -scene->z_angle);
}

void ft_linux_move_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 65362)
		ft_zmove_scene(scene, scene->zmove);
	else if (keycode == 65361)
		ft_xmove_scene(scene, scene->xmove);
	else if (keycode == 65364)
		ft_zmove_scene(scene, -scene->zmove);
	else if (keycode == 65363)
		ft_xmove_scene(scene, -scene->xmove);
	else if (keycode == 122)
		ft_ymove_scene(scene, -scene->ymove);
	else if (keycode == 120)
		ft_ymove_scene(scene, scene->ymove);
}

void ft_linux_ui_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 117)
		scene->ui = -scene->ui;
	else if (keycode == 65307)
		exit(0);
}

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
	ft_move_figure(scene->current_figure, vec);
}

void ft_move_figure(t_figure *figure, t_vec vec)
{
	if (figure->type == SPHERE)
		ft_move_sphere(figure, vec);
	else if (figure->type == PLANE)
		ft_move_plane(figure, vec);
	else if (figure->type == CYLINDER)
		ft_move_cylinder(figure, vec);
}
