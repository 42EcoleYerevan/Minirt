#include "minirt.h"

int main()
{
    void		*mlx;
    void		*win;
    t_camera	*camera;
    t_scene		*scene;

    mlx = mlx_init();
    camera = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
    scene = new_scene(800, 600);
    scene->ambient = new_ambient(new_color(255,255,255, 1), 0.3);
    scene->cams = camera;
	scene->light = new_light(new_color(255, 255, 255, 1), new_vector(0, 70, 10), 0.7);
    scene->figure = new_sphere(new_vector(0, 0, -50), 10, new_color(255, 0, 0, 1));
	scene->figure->next = new_sphere(new_vector(10, 0, -50), 10, new_color(0, 255, 150, 1));
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
    scene_render(mlx, win, scene, 0, 0);
    mlx_loop(mlx);
    return (0);
}
