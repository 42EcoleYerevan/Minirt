#include "minirt.h"

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
}

int key_hook(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	scene->button = keycode;
	if (keycode == 53)
		exit(0);
	if (OSFLAG == 1)
	{
		ft_rotate_keyhook(keycode, scene);
		ft_move_keyhook(keycode, scene);
		ft_ui_keyhook(keycode, scene);
	}
	else if (OSFLAG == 2)
	{
		ft_linux_rotate_keyhook(keycode, scene);
		ft_linux_move_keyhook(keycode, scene);
	}
	render(scene);
	return (0);
}
