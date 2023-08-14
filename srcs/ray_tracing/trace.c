#include "minirt.h"

float	compute_light(t_scene *scene, int dist, t_light *lights, t_vec *ray)
{
	float	bright;
	t_vec	*point;
	t_vec	*l;
	float	dot;

	bright = 0;
	point = new_vector(ray->x, ray->y, ray->z);
	printf("\nx1 = %f, y1 = %f, z1 = %f\n", point->x, point->y, point->z);
	ft_vec_mult(point, dist);
	printf("x2 = %f, y2 = %f, z2 = %f\n", point->x, point->y, point->z);
	ft_vec_add(point, scene->cams->origin);
	printf("x3 = %f, y3 = %f, z3 = %f\n", point->x, point->y, point->z);
	bright += scene->ambient->brightness;
	l = vec_substr(lights->center, point);
	vec_norm(point);
	printf("x4 = %f, y4 = %f, z4 = %f ", point->x, point->y, point->z);
	dot = vec_mult_dot(point, l);
	printf("dot = %f ", dot);
	if (dot > 0)
		bright += (lights->brightness * dot) / (ft_vec_len(point) * ft_vec_len(l));
	printf("brigth = %f\n", bright);
	return (bright);
}

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
	int			dist;

	vplane = new_vplane(scene->width, scene->height, scene->cams->fov);
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
			color = 0;
			vec_norm(ray);
			dist = sphere_inter(scene->cams, ray, (t_sphere *)scene->figure->data);
			if (dist != 0)
				color = get_color(255, 0, 0, compute_light(scene, dist, scene->light, ray));
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}