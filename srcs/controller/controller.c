#include "minirt.h"

int key_hook(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	scene->button = keycode;
	if (OSFLAG == 1)
		ft_mac_hooks(keycode, scene);
	else if (OSFLAG == 2)
		ft_linux_hooks(keycode, scene);
	render(scene);
	return (0);
}
