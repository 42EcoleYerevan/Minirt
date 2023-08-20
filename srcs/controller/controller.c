#include "minirt.h"

int key_hook(int keycode, t_scene *scene)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		scene->cams->origin->y += 1;
	else if (keycode == 0)
		scene->cams->origin->x -= 1;
	else if (keycode == 1)
		scene->cams->origin->y -= 1;
	else if (keycode == 2)
		scene->cams->origin->x += 1;
	return (0);
}
