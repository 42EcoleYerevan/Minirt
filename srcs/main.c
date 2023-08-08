#include "minirt.h"

void	exit_err(char *str)
{
	while(*str)
		write(2, str++, 1);
	exit(1);
}

int main()
{
	void		*mlx;
	void		*img;
	void		*win;
	t_vec		*sphere_center;
	t_sphere	*sphere;
	t_vec		*cam_origin;
	t_vec		*cam_direction;
	t_camera	*camera;
	t_scene		*scene;

	mlx = mlx_init();
	sphere_center = new_vector(3, 2, -32);
	sphere = new_sphere(sphere_center, 12/2);
	cam_origin = new_vector(0, 0, 0);
	cam_direction = new_vector(0, 0, -1);
	camera = new_camera(cam_origin, cam_direction, 70);
	scene = new_scene(camera, sphere);
	scene->width = 800;
	scene->height = 600;
	win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	ray_tracing(mlx, win, scene);
	//free_scene(scene);
	mlx_loop(mlx);
	return (0);
}
