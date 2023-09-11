#include "minirt.h"

void ft_mac_hooks(int keycode, t_scene *scene)
{
	ft_ui_keyhook(keycode, scene);
	if (scene->current_figure)
	{
		ft_mac_figure_move_hook(scene, keycode);
		ft_mac_rotate_figure_hook(scene, keycode);
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
