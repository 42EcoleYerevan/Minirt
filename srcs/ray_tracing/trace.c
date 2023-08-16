#include "minirt.h"

float	calc_light(t_scene *scene, int t, t_light *light, t_vec *ray, t_sphere *sph)
{
	float	bright;
	t_vec	*point;
	t_vec	*l;
	t_vec	*n;
	float	dot;

	point = new_vector(ray->x * t, ray->y * t, ray->z * t);
	ft_vec_add(point, scene->cams->origin);
	n = new_vector(point->x, point->y,point->z);
	n = vec_substr(n, sph->center);
	vec_norm(n);
	bright = scene->ambient->brightness;
	while (light)
	{
		l = vec_substr(light->center, point);
		dot = vec_mult_dot(n, l);
		if (dot > 0)
			bright += (light->brightness * dot) / (ft_vec_len(n) * ft_vec_len(l));
		free(l);
		light = light->next;
	}
	free(point);
	free(n);
	if (bright > 1)
		return (1);
	return (bright);
}

int	ray_trace(t_vec *ray, t_scene *scene, t_figure *sphere)
{
	int			color;
	float		t;
	float		min_t;
	t_sphere	*obj;

	color = 0;
	min_t = 0;
	obj = NULL;
	while (sphere)
	{
		t = sphere_inter(scene->cams, ray, (t_sphere *)sphere->data);
		if ((t < min_t || min_t == 0)&& t != 0)
			min_t = t;
		if (t == min_t)
			obj = (t_sphere *)sphere->data;
		sphere = sphere->next;
	}
	if (min_t > 0)
		color = get_color(obj->color->r,obj->color->g, obj->color->b,
						  calc_light(scene, min_t, scene->light, ray, obj));
	free(ray);
	return (color);
}

void	scene_render(void *mlx, void *win, t_scene *scene, int mlx_x, int mlx_y)
{
	float		x_angle;
	float		y_angle;
	t_vplane	*vplane;
	t_vec		*ray;

	vplane = new_vplane(scene->width, scene->height, scene->cams->fov);
	y_angle = scene->height / 2;
	while (y_angle >= (scene->height / 2) * (-1))
	{
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while(x_angle <= scene->width / 2)
		{
			ray = new_vector(x_angle * vplane->x_pixel, y_angle * vplane->y_pixel, -1);
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, ray_trace(ray, scene, scene->figure));
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}