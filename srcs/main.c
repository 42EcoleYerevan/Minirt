#include "geometry.h"
#include "minirt.h"

int render(void *scene)
{
	t_scene *tscene;

	tscene = (t_scene *)scene;
    scene_render(tscene->mlx, tscene->win, scene, 0, 0);
	return (0);
}

int main()
{
    void		*mlx;
    void		*win;
	t_camera	*camera;
    t_scene		*scene;

	scene = new_scene(800, 600);
	ft_parser("scenes/new.rt", scene);
	ft_print_scene(scene);

    mlx = mlx_init();
    camera = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	scene->cams = camera;
	scene->mlx = mlx;
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	scene->win = win;
	mlx_loop_hook(mlx, render, scene);
	mlx_key_hook(win, key_hook, scene);
    mlx_loop(mlx);
    return (0);
}
