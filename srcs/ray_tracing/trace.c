#include "minirt.h"

float	cacl_diffuse(t_vec *l, t_vec *n, t_light *light)
{
	float	dot;

	dot = ft_vec_mult_dot(n, l);
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
	r = ft_vec_substr(v, l);
	free(v);
	v = new_vector(-(d->x), -(d->y), -(d->z));
	r_dot_v = ft_vec_mult_vec(r, v);
	if (r_dot_v > 0)
		res = light->brightness * powf(r_dot_v / (ft_vec_len(r) * ft_vec_len(v)), s);
	free(v);
	free(r);
	return (res);
}

float	calc_light(t_vec *p, t_vec *ray, t_scene *scene, t_sphere *sph)
{
	float		bright;
	t_vec		*l;
	t_vec		*n;
	t_light		*light;
    t_figure	*shadow = NULL;
	
	light = scene->light;
	n = new_vector(p->x, p->y,p->z);
	n = ft_vec_substr(n, sph->center);
	ft_vec_norm(n);
	bright = scene->ambient->brightness;
	while (light)
	{
        l = ft_vec_substr(light->center, p);
        closest_inter(scene->figure, &shadow, p, l, 0.001);
        if (shadow != NULL)
        {
			light = light->next;
			free(l);
		 	continue ;
		}
		bright += cacl_diffuse(l, n, light);
		if (sph->specular > 0)
			bright += calc_specular(ray, l, n, light, sph->specular);
		free(l);
		light = light->next;
	}
	free(p);
	free(n);
	if (bright > 1)
		return (1);
	return (bright);
}

float		closest_inter(t_figure *figure, t_figure **obj, t_vec *o, t_vec *d, float min_val)
{
	float	min_t;
	float	t;

	min_t = 2000000;
	while (figure)
	{
		if (figure->type == SPHERE)
			t = sphere_inter(o, d, (t_sphere *)figure->data);
		else if (figure->type == PLANE)
			t = plane_inter(o, d, (t_plane *)figure->data);
		if (t > min_val && t < min_t)
        {
            min_t = t;
            *obj = figure;
        }
		figure = figure->next;
	}
	if (min_t == 2000000)
		return (0);
	return (min_t);
}

int	ray_trace(t_vec *d, t_vec *o, t_scene *scene, t_figure *figure)
{
	float		min_t;
	t_figure	*obj;
	t_vec		*p;

	obj = NULL;
	(void)scene;
	min_t = closest_inter(figure, &obj, o, d, 0);
	if (min_t <= 0)
		return (0);
	p = new_vector(d->x * min_t, d->y * min_t, d->z * min_t);
	ft_vec_add(p, o);
	// return (get_color(obj->color->r,obj->color->g, obj->color->b, calc_light(p, d, scene, obj)));
	return (get_color(obj->color->r,obj->color->g, obj->color->b, 1));
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
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, ray_trace(ray, scene->cams->origin, scene, scene->figure));
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
