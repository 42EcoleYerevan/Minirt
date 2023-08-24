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
	ft_vec_mult(v, ft_vec_mult_dot(n, l));
	r = ft_vec_substr(v, l);
	// free(v);
	v = new_vector(-(d->x), -(d->y), -(d->z));
	r_dot_v = ft_vec_mult_dot(r, v);
	if (r_dot_v > 0)
		res = light->brightness * powf(r_dot_v / (ft_vec_len(r) * ft_vec_len(v)), s);
	// free(v);
	// free(r);
	return (res);
}

float	calc_light(t_vec *p, t_vec *ray, t_scene *scene, t_figure *figure)
{
	float		bright;
	t_vec		*l;
	t_vec		*n;
	t_light		*light;
    t_figure	*shadow = NULL;
	
	light = scene->light;
	n = new_vector(p->x, p->y,p->z);
	n = ft_vec_substr(n, ((t_sphere *)figure->data)->center);
	ft_vec_norm(n);
	bright = scene->ambient->brightness;
	while (light)
	{
        l = ft_vec_substr(light->center, p);
        closest_inter(scene->figure, &shadow, p, l);
        if (shadow != NULL)
        {
			light = light->next;
			free(l);
		 	continue ;
		}
		bright += cacl_diffuse(l, n, light);
		if (((t_sphere *)figure->data)->specular > 0)
			bright += calc_specular(ray, l, n, light, ((t_sphere *)figure->data)->specular);
		light = light->next;
	}
	if (bright > 1)
		return (1);
	return (bright);
}

float		closest_inter(t_figure *figure, t_figure **obj, t_vec *o, t_vec *d)
{
	float	min_t;
	float	t;

	min_t = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			t = sphere_inter(o, d, (t_sphere *)figure->data);
		if (figure->type == PLANE)
			t = plane_inter(o, d, (t_plane *)figure->data);
		// if (t > min_val && t < min_t)
		if ((t > 0) && (t < min_t || obj == NULL))
        {
            min_t = t;
            *obj = figure;
        }
		figure = figure->next;
	}
	return (min_t);
}

float calc_plane_light(t_vec *p, t_scene *scene, t_plane *plane)
{
    float bright = scene->ambient->brightness;
    t_vec *l;
    t_light *light = scene->light;
	t_figure *shadow = NULL;

    while (light)
    {
        l = ft_vec_substr(light->center, p);
		closest_inter(scene->figure, &shadow, p, l);
        if (shadow != NULL)
        {
			light = light->next;
			free(l);
		 	continue ;
		}
        float distance_to_light = ft_vec_len(l);
        float dot = ft_vec_mult_dot(plane->normal, l);
        if (dot > 0)
            bright += (light->brightness * dot) / (ft_vec_len(plane->normal) * distance_to_light);
        free(l);
        light = light->next;
    }
    if (bright > 1)
        return 1;
    return bright;
}

int	ray_trace(t_vec *d, t_vec *o, t_scene *scene, t_figure *figure)
{
	float		min_t;
	t_figure	*obj;
	t_vec		*p;

	obj = NULL;
	min_t = closest_inter(figure, &obj, o, d);
	if (min_t == INFINITY || obj == NULL)
		return (0);
	p = new_vector(d->x * min_t, d->y * min_t, d->z * min_t);
	ft_vec_add(p, o);
	if (obj && obj->type == PLANE)
		return get_color(obj->color->r, obj->color->g, obj->color->b, calc_plane_light(p, scene, obj->data));
	return (get_color(obj->color->r,obj->color->g, obj->color->b, calc_light(p, d, scene, obj)));
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
			ft_vec_norm(ray);
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, ray_trace(ray, scene->cams->origin, scene, scene->figure));
			// free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
