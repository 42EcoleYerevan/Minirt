#include "minirt.h"

void	ft_mouse_scroll_hook(int keycode, t_scene *scene)
{
	if (keycode == 4)
		scene->cams->origin->z -= 10;
	else if (keycode == 5)
		scene->cams->origin->z += 10;
}

int	ft_mousedown_hook(int keycode, int x, int y, t_scene *scene)
{
	(void)x;
	(void)y;
	scene->button = keycode;
	ft_mouse_scroll_hook(keycode, scene);
	return (0);
}

int ft_mouseup_hook(int keycode, int x, int y, t_scene *scene)
{
	(void)scene;
	(void)keycode;
	(void)x;
	(void)y;
	scene->button = -1;
	return (0);
}

int ft_mousemove_hook(int x, int y, t_scene *scene)
{
	static int old_x = 0;
	static int old_y = 0;

	if (scene->button == 1 && old_x != 0 && old_y != 0)
	{
		/* scene->cams->origin->x -= x - old_x; */
		/* scene->cams->origin->y += y - old_y; */
		scene->cams->direction->x -= x - old_x;
		scene->cams->direction->y += y - old_y;
		ft_vec_norm(scene->cams->direction);
	}
	old_x = x;
	old_y = y;
	return (0);
}
