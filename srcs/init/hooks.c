#include "minirt.h"

void	ft_init_hooks(t_scene *scene)
{
	mlx_hook(scene->win, 4, 0, ft_mousedown_hook, scene);
	mlx_hook(scene->win, 5, 0, ft_mouseup_hook, scene);
	mlx_hook(scene->win, 6, 0, ft_mousemove_hook, scene);
	mlx_key_hook(scene->win, key_hook, scene);
}
