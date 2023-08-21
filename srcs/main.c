#include "minirt.h"

void ft_print_matrix(float *matrix)
{
	int i;

	i = 0;
	while (i < 16)
	{
		printf("%f ", matrix[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
		i++;
	}
}

int render(void *scene)
{
	t_scene *tscene;

	tscene = (t_scene *)scene;
	ft_move_scene_to_camera(tscene, tscene->cams);
    scene_render(tscene->mlx, tscene->win, scene, 0, 0);
	return (0);
}

int main()
{
    void		*mlx;
    void		*win;
    t_scene		*scene;

	scene = new_scene(WIDTH, HEIGHT);
	scene->x_angle = 0;
	scene->y_angle = 0;
	scene->z_angle = 0;
	ft_parser("scenes/new.rt", scene);
	ft_print_scene(scene);

    mlx = mlx_init();
	scene->mlx = mlx;
    win = mlx_new_window(mlx, scene->width, scene->height, "miniRT");
	scene->win = win;
	render(scene);
	ft_init_hooks(scene);
    mlx_loop(mlx);

    return (0);
}
