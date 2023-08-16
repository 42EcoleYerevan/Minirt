#include "minirt.h"


int main()
{
    void		*mlx;
    void		*win;
	t_camera	*camera;
    t_scene		*scene;

	scene = new_scene(800, 600);
	ft_parser("scenes/test.rt", scene);
	ft_print_scene(scene);

    mlx = mlx_init();
    camera = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
    scene_render(mlx, win, scene, 0, 0);
    mlx_loop(mlx);
    return (0);
}
