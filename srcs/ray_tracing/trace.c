#include "minirt.h"

void	ray_tracing(void *mlx, void *win, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			color;
	float		y_ray;
	float		x_ray;
	t_vec		*ray;
	t_vplane	*vplane;

	vplane = get_new_vplane(scene->width, scene->height, scene->cams->fov);
	mlx_y = 0;
	y_angle = scene->height / 2;
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while(x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vec_norm(ray);
			color = sphere_inter(scene->cams, ray, scene->sphere);
			if (color != 0)
				color = 99777225;
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}