#include "minirt.h"

int render(void *scene)
{
	t_scene		*tscene;

	tscene = (t_scene *)scene;
    scene_render(tscene->mlx, tscene->win, scene, 0, 0);
	return (0);
}
