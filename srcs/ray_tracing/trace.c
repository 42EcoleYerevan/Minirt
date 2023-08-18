#include "minirt.h"

float	cacl_diffuse(t_vec *l, t_vec *n, t_light *light)
{
	float	dot;

	dot = vec_mult_dot(n, l);
	if (dot > 0)
		return ((light->brightness * dot) / (ft_vec_len(n) * ft_vec_len(l)));
	return (0);
}

float	calc_specular(t_vec	*d, t_vec *l, t_vec *n, t_light *light, int s)
{
	t_vec	*v;
	t_vec	*r;
	float	r_dot_v;
	float	res;

	res = 0;
	v = new_vector(2 * n->x, 2 * n->y, 2 * n->z);
	ft_vec_mult(v, ft_vec_mult_vec(n, l));
	r = vec_substr(v, l);
	free(v);
	v = new_vector(-(d->x), -(d->y), -(d->z));
	r_dot_v = ft_vec_mult_vec(r, v);
	if (r_dot_v > 0)
		res = light->brightness * powf(r_dot_v / (ft_vec_len(r) * ft_vec_len(v)), s);
	free(v);
	free(r);
	return (res);
}

float	calc_light(t_scene *scene, int t, t_light *light, t_vec *ray, t_sphere *sph)
{
	float	bright;
	t_vec	*point;
	t_vec	*l;
	t_vec	*n;


	point = new_vector(ray->x * t, ray->y * t, ray->z * t);
	ft_vec_add(point, scene->cams->origin);
	n = new_vector(point->x, point->y,point->z);
	n = vec_substr(n, sph->center);
	vec_norm(n);
	bright = scene->ambient->brightness;
	while (light)
	{
		l = vec_substr(light->center, point);
		bright += cacl_diffuse(l, n, light);
		if (sph->specular > 0)
			bright += calc_specular(ray, l, n, light, sph->specular);
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

	color = get_color(255,255,255,1);
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
