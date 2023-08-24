#include "geometry.h"
#include "minirt.h"

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
}

void	ft_move_keyhook(int keycode, t_scene *scene)
{
	if (keycode == 126)
		ft_zmove_scene(scene, scene->zmove);
	else if (keycode == 123)
		ft_xmove_scene(scene, -scene->xmove);
	else if (keycode == 125)
		ft_zmove_scene(scene, -scene->zmove);
	else if (keycode == 124)
		ft_xmove_scene(scene, scene->xmove);
}

int key_hook(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	ft_rotate_keyhook(keycode, scene);
	ft_move_keyhook(keycode, scene);
	render(scene);
	return (0);
}
