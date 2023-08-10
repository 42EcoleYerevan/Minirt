#include "minirt.h"

void	err_exit(char *str)
{
	while(*str)
		write(2, str++, 1);
	exit(1);
}

int main()
{
	void		*mlx;
	void		*win;
	t_vec		*sphere_center;
	t_sphere	*sphere;
	t_vec		*cam_origin;
	t_vec		*cam_direction;
	t_camera	*camera;
	t_scene		*scene;

	mlx = mlx_init();
	sphere = new_sphere(new_vector(3, 2, -32), 12/2);
	camera = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	scene = new_scene(camera, 800, 600);
	win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	ray_tracing(mlx, win, scene);
	//free_scene(scene);
	mlx_loop(mlx);
	return (0);
}
