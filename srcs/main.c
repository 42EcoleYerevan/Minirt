#include "minirt.h"

int main()
{
    void		*mlx;
    void		*win;
    t_sphere	*sphere;
    t_camera	*camera;
    t_scene		*scene;

    mlx = mlx_init();
    sphere = new_sphere(new_vector(0, 0, -32), 12 / 2);
    camera = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
    scene = new_scene(new_ambient(get_color(255,255,255, 1), 0.2), camera, 800, 600);
	scene->light = new_light(get_color(255, 255, 255, 1), new_vector(0, 22, -1), 0.5);
    scene->sphere = sphere;
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
    ray_tracing(mlx, win, scene);
    //free_scene(scene);
    mlx_loop(mlx);
    return (0);
}
