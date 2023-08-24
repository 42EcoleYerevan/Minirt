#include "minirt.h"

void ft_camera_keyhook(int keycode, t_scene *scene)
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

int key_hook(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	ft_camera_keyhook(keycode, scene);
	render(scene);
	return (0);
}
